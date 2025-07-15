#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "PieceManager.h"
#include "DragManager.h"
#include "PawnLogic.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u{800, 800}), "King Chess");
    const int row = 2, col = 6; // sprite sheeet

    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("images/board.png")) {
        return -1;
    }

    sf::Sprite board(boardTexture);
    auto windowSize = window.getSize();
    // scale constant = winSize / textureSize
    float scaleX = static_cast<float>(windowSize.x)/boardTexture.getSize().x;
    float scaleY = static_cast<float>(windowSize.y)/boardTexture.getSize().y;
    board.setScale({scaleX, scaleY}); // scale the board to fit the win size

    TextureManager textureManager;
    // updated here if changed sprite sheet
    if(!textureManager.loadSpritesheet("images/figures.png", col, row))
    {
        return -1;
    }

    PieceManager pieceManager(textureManager);
    pieceManager.loadInitialPosition();

    DragManager dragManager(pieceManager);

    // game condition
    while(window.isOpen()){
        while(std::optional<sf::Event> event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            dragManager.handleEvent(window,event);
        }

        window.clear();
        window.draw(board);
        pieceManager.draw(window,dragManager.getDraggedIndex());
        dragManager.drawDraggingPiece(window);
        window.display();
    }

    return 0;
}