#pragma once

void gameInitialize();
void gameUpdate(double deltaSeconds);
void gameRender();
void gameShutdown();

void gameReset();
void gameLoadLevel(int levelIndex);
void gameUpdatePaddle(double deltaSeconds);
void gameUpdateBall(double deltaSeconds);
void gameCheckCollisions();

void gameOnKeyDown(unsigned char key, int x, int y);
void gameOnKeyUp(unsigned char key, int x, int y);
void gameOnSpecialKeyDown(int key, int x, int y);
void gameOnSpecialKeyUp(int key, int x, int y);
void gameOnMouse(int button, int state, int x, int y);
void gameOnMotion(int x, int y);
