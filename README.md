# SnakeGame-C++-Qt
A classic snake game framework implemented with C++ and Qt Creator.

## 项目介绍
基于 C++ 和 Qt 开发的贪吃蛇小游戏，实现了多种苹果机制和生命周期管理。

## 技术栈
- C++
- Qt Widgets
- STL vector
- 面向对象设计

## 功能特点
- 普通苹果（概率生成 + 生命周期）
- 金苹果（低概率 + 高奖励）
- 毒苹果（扣分 + 缩短蛇身）
- 统一的苹果生命周期管理
- 安全迭代器删除机制
- 游戏状态管理

## 技术难点
- vector 迭代器失效问题处理
- erase 安全写法
- 概率生成控制
- Qt 绘图机制

## 项目结构
- Snake 类
- Apple 类
- GameController 类
- UI 页面管理
