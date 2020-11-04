#include <SFML/Graphics.hpp>
#include <iostream>
#include"player.h"
#include"projectile.h"
#include"enemy.h"
#include <vector>
#include"random.h"
#include <Font.Dlg>
using namespace std;

int main()
{
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;

    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    sf::RenderWindow window(sf::VideoMode(1080, 789), "SFML works!");
    sf::Texture textureSprite, textureEnemy;
    textureSprite.loadFromFile("sprite.png");
    textureEnemy.loadFromFile("enemy.png");

    class player player1;
    player1.sprite.setTexture(textureSprite);

    //bullet vector
    vector<projectile>::const_iterator iter;
    vector<projectile> projectileArray;
    class projectile projectile1;
    //Enemy vector
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;
    class enemy enemy1;
    enemy1.sprite.setTexture(textureEnemy);
    enemy1.rect.setPosition(200, 200);
    enemyArray.push_back(enemy1);




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //clock
        sf::Time elaped1 = clock.getElapsedTime();
        sf::Time elaped2 = clock2.getElapsedTime();
        sf::Time elaped3 = clock3.getElapsedTime();


        counter = 0;
        if (elaped2.asSeconds() >= 0.5)
        {
            clock2.restart();
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
                {
                    player1.hp -= enemyArray[counter].attackDamage;
                }
                counter++;
            }
        }
        cout << player1.hp << endl;

        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    cout << "colliston" << endl;
                    projectileArray[counter].destroy = true;
                    enemyArray[counter2].hp--;
                    if (enemyArray[counter2].hp <= 0)
                    {
                        enemyArray[counter2].alive = false;
                    }
                }
                counter2++;
            }
            counter++;
        }

        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if (enemyArray[counter].alive == false)
            {
                cout << "alive false" << endl;
                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }

        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if (projectileArray[counter].destroy == true)
            {
                cout << "destroy" << endl;
                projectileArray.erase(iter);
                break;
            }
            counter++;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        {
            enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
            enemyArray.push_back(enemy1);
        }

        if (elaped1.asSeconds() >= 0.25)
        {
            clock.restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                projectile1.rect.setPosition(player1.rect.getPosition().x + 40, player1.rect.getPosition().y + 60);
                projectile1.direction = player1.direction;
                projectileArray.push_back(projectile1);
            }
        }
        counter = 0;
        for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            projectileArray[counter].update();
            window.draw(projectileArray[counter].rect);
            counter++;
        }

        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].update();
            enemyArray[counter].updateMovement();
            window.draw(enemyArray[counter].rect);
            window.draw(enemyArray[counter].sprite);
            counter++;
        }


        player1.update();
        player1.updateMovement();
        window.draw(player1.sprite);

        window.display();
    }

    return 0;
}