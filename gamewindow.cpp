#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <Qpainter>
#include <QColor>
#include <QPaintEvent>
#include <QKeyEvent>
#include <Qsettings>

gamewindow::gamewindow(QWidget *parent)
    : QWidget(parent),
      m_timer(new QTimer(this))
    , ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->pageMenu);  //先进入主菜单界面

    connect(ui->pushButtonStart, &QPushButton::clicked, this, [=](){
        startGame();  //开始游戏按键
    });

    connect(ui->pushButtonRank, &QPushButton::clicked, this, [=](){
        updateRankPage();
        ui->stackedWidget->setCurrentWidget(ui->pageRank);  //进入计分排行界面
    });

    connect(ui->pushButtonIntro, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->pageIntro);  //进入游戏介绍界面
    });


    connect(ui->pushButtonBack, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);  //游戏介绍界面返回主菜单
    });

    connect(ui->pushButtonBAck, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);  //计分排行界面返回主菜单
    });

    connect(ui->pushButtonagain, &QPushButton::clicked, this, [=](){
        startGame();  //游戏结束后再来一局
    });

    connect(ui->pushButtonback, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->pageMenu);  //游戏结束后返回主菜单
    });

    ui->gameView->setController(&m_controller);


    setFixedSize(800,600);  //固定窗口大小，宽600像素，高400像素
    connect(m_timer,&QTimer::timeout,this,&gamewindow::gameLoop);  //timeout为信号，gameLoop为槽，每当时间到了调用gameLoop
    setFocusPolicy(Qt::StrongFocus);

}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::startGame()
{
    m_controller.init();      // 重置蛇、苹果、分数
    m_timer->start(150);  //150ms一帧
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
}


void gamewindow::gameLoop()
{     
    m_controller.update();
    if (m_controller.isGameOver())
    {
        m_timer->stop();

        m_lastScore = m_controller.score();   //取分数

        ui->labelFinalScore->setText(
            QString("%1").arg(m_lastScore)
            );

        saveScore(m_lastScore);
        updateRankPage();

        ui->stackedWidget->setCurrentWidget(ui->pageOver);
        return;
    }
    update();  //Qwidget::update,触发重绘的函数
}


void gamewindow::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_W:
    case Qt::Key_Up:
        m_controller.setDirection(Snake::Up);
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        m_controller.setDirection(Snake::Down);
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
        m_controller.setDirection(Snake::Left);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        m_controller.setDirection(Snake::Right);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void gamewindow::saveScore(int score)
{
    QSettings settings("ECNU", "SnakeGame");

    QList<int> scores = settings.value("scores").value<QList<int>>();
    scores.append(score);

    std::sort(scores.begin(), scores.end(), std::greater<int>());

    while (scores.size() > 5)
        scores.removeLast();

    settings.setValue("scores", QVariant::fromValue(scores));
}

void gamewindow::updateRankPage()
{
    QSettings settings("ECNU", "SnakeGame");
    QList<int> scores = settings.value("scores").value<QList<int>>();

    while (scores.size() > 5)
    {
        scores.removeLast();
    }
    // 给五个标签分别赋值，没有分数的标签显示0
    ui->labelScore1->setText(scores.size() > 0 ? QString("%1").arg(scores[0]) : "0");
    ui->labelScore2->setText(scores.size() > 1 ? QString("%1").arg(scores[1]) : "0");
    ui->labelScore3->setText(scores.size() > 2 ? QString("%1").arg(scores[2]) : "0");
    ui->labelScore4->setText(scores.size() > 3 ? QString("%1").arg(scores[3]) : "0");
    ui->labelScore5->setText(scores.size() > 4 ? QString("%1").arg(scores[4]) : "0");

}
