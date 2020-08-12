#include "pch.h"
#include "Graphics/Texture.h"
#include "Engine.h"

sn::ResourceManager resourceManager;
sn::Renderer renderer;
sn::InputSystem inputSystem;
sn::FrameTimer timer;

sn::Engine engine;

int main(int, char**)
{
	engine.Startup();

	sn::Texture* car = resourceManager.Get<sn::Texture>("cars.png", &renderer);
	sn::Texture* background = resourceManager.Get<sn::Texture>("background.png", &renderer);
	
	sn::Vector2 position{ 400,300 };
	sn::Vector2 velocity{ 0, 0 };
	float angle{ 0 };
	
	SDL_Event event;
	bool quit = false;
	while (!quit) {

		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}

		timer.Tick();
		engine.Update();

		//player controls
		if(inputSystem.GetButtonState(SDL_SCANCODE_A) == sn::InputSystem::eButtonState::HELD) {
			angle = angle - 250.0f * timer.DeltaTime();
			position.x = position.x - 200.0f * timer.DeltaTime();
		}

		if (inputSystem.GetButtonState(SDL_SCANCODE_D) == sn::InputSystem::eButtonState::HELD) {
			angle = angle + 250.0f * timer.DeltaTime();
			position.x = position.x + 200.0f * timer.DeltaTime();
		}

		if (inputSystem.GetButtonState(SDL_SCANCODE_S) == sn::InputSystem::eButtonState::HELD) {
			position.y = position.y + 200.0f * timer.DeltaTime();
		}

		//physics
		sn::Vector2 force{ 0,0 };
		if (inputSystem.GetButtonState(SDL_SCANCODE_W) == sn::InputSystem::eButtonState::HELD) {
			force = sn::Vector2::forward * 500.0f;
		}
		force = sn::Vector2::rotate(force, sn::DegreesToRadians(angle));

		velocity += force * timer.DeltaTime();
		velocity *= 0.98f;
		position += velocity * timer.DeltaTime();

		renderer.BeginFrame();

		background->Draw({ 0, 0 }, { 1.0f , 1.0f }, 0);
		car->Draw({ 126, 120, 52, 102 },  position, { 1.0f , 1.0f }, angle);

		renderer.EndFrame();
	}
	
	engine.Shutdown();

	return 0; 
}