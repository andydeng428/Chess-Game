#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Chess Game");
    ChessGame game;
    game.startGame();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / tileSize;
                int y = event.mouseButton.y / tileSize;
                game.handleClick(x, y);
            }
        }
        window.clear();
        game.drawBoard(window);
        window.display();
    }
    return 0;
}
