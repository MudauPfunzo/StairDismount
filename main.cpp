#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Stair Dismount");

	sf::Event event;
	sf::Texture texture;
	texture.loadFromFile("images/ragdoll.png");

	sf::IntRect rectSourceSprite(300, 0, 300, 400);
	sf::Sprite sprite(texture, rectSourceSprite);
	sf::Clock clock;

	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();

			if (event.type == sf::Event::MouseLeft) {
				sf::Vector2f scale = sprite.getScale();
				sprite.setScale(scale.x * 1.0f, scale.y * 1.3f);
				//event  to make the ragdoll fall
				sprite.move(scale);
			}
				

		}

		if (clock.getElapsedTime().asSeconds() > 1.0f) {
			if (rectSourceSprite.left == 600)
				rectSourceSprite.left = 0;
			else
				rectSourceSprite.left += 300;

			sprite.setTextureRect(rectSourceSprite);
			clock.restart();
		}

		//movememt and falling

		renderWindow.clear();
		renderWindow.draw(sprite);
		renderWindow.display();
	}

	return 0;

}