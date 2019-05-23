// Clickcoins by vortex

#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "click.hh"
#define FONT "DejaVuSans.ttf"

void click(Player& player){
    player.total_clicks = player.total_clicks + 1;
    player.total_coins = player.total_coins + player.click_bonus;
}


int main() {
    sf::RenderWindow win(sf::VideoMode(640, 480), "ClickGame");
    sf::Font default_font;
    if(!default_font.loadFromFile(FONT)){
        std::cout << "Cannot load default font" << std::endl;
    }
    
    Player p;
    
    sf::Texture clicker;
    sf::Sprite clicker_sprite;
    
    if(!clicker.loadFromFile("clickbutton.png")){
        std::cout << "Cannot load button sprite. Please create a 300x300 image named clickbutton.png to fix." << std::endl;
    }
    
    clicker_sprite.setPosition(240.0f, 240.0f); // center of screen
    clicker_sprite.setTexture(clicker);
    
    while(win.isOpen()){
        // routine
        sf::Event e;
        while(win.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                win.close();
            }
            
            if(e.type == sf::Event::MouseButtonPressed){
                // create a 2d vector with the mouse coords at click
                sf::Vector2i mouse_pos(e.mouseButton.x, e.mouseButton.y);
                sf::Vector2f click_pos(static_cast<float>(e.mouseButton.x), static_cast<float>(e.mouseButton.y));
                
                if(clicker_sprite.getGlobalBounds().contains(click_pos)){
                    click(p);
                    if(p.total_clicks % 100 == 0){
                        p.click_bonus = p.click_bonus + 5;
                    }
                    std::cout << "click!!!" << std::endl;
                }
            }
        }
        win.clear(sf::Color::White);
        std::string stats = "Total Clicks: ";
        stats.append(std::to_string(p.total_clicks));
        stats.append("\nTotal Coins: ");
        stats.append(std::to_string(p.total_coins));
        stats.append("\n");
        sf::Text s(stats, default_font, 30);
        s.setFillColor(sf::Color::Black);
              
        win.draw(s);
        win.draw(clicker_sprite);
        win.display();
    }
        
    return 0;
}