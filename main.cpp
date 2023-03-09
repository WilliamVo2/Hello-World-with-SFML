#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML_Hello-World");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Press arrows for direction and Space for rotate", font, 20);
    
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
	  // Close window: exit
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
	// Movement set up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	  sprite.move(1, 0);
	  sprite.setTextureRect(sf::IntRect(62, 65, 80, 30));}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	  sprite.move(-1, 0);
	  sprite.setTextureRect(sf::IntRect(35, 32, 30, 33));}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	  sprite.move(0, -1);
	  sprite.setTextureRect(sf::IntRect(65, 95, 64, 40)); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	  sprite.move(0, 1);
	  sprite.setTextureRect(sf::IntRect(2, 1, 30, 30)); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	  sprite.rotate(5);
	}
	
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
	      // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
