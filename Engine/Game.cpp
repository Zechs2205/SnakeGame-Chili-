
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	snake(rng, brd),
	goal(rng, brd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if(wnd.kbd.KeyIsPressed(VK_UP)) {
		delta_loc = { 0,-1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		delta_loc = { 0,1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		delta_loc = { 1,0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		delta_loc = { -1,0 };
	}
	if (snake.Touch()) {
		
	}
	else {
		RateCounter++;
		if (RateCounter >= changerate) {
			RateCounter = 0;
			if (snake.Eat(goal.GetLocation())) {
				snake.Grow();
				goal.Respawn(rng, brd, snake.Eat(goal.GetLocation()));
			}
			snake.Moveby(delta_loc,
				brd.insideBoard(snake.Getlocation(delta_loc)));
		}
	}
}

void Game::GameOver()
{
	gfx.DrawRect(0, 0, 400, 400, Colors::Red);
}

void Game::ComposeFrame()
{
	if (snake.Touch()) {
		GameOver();
	}
	else {
		snake.SnakeDraw(brd);
		goal.Draw(brd);
	}
}
