#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace sf;
using namespace std::chrono_literals;
/*Создайте 3 круга разных цветов и размеров.
Перемещайте их из исходного положения вниз до конца экрана с разной скоростью.
При достижении конца экрана остановите фигуры.*/
int main()
{
	int weight_window = 980;
	int height_window = 800;
	RenderWindow window(sf::VideoMode(weight_window, height_window), "y menya net problem krome moey bushki!!!");

	int c1_r = 80;
	int c_x1 = 90;
	int c1_position = 50;

	CircleShape c1(c1_r);
	c1.setOrigin((c1_r), (c1_r));
	c1.setFillColor(sf::Color(255, 196,155));
	c1.setPosition(c_x1, c1_position);

	int c2_r = 70;
	int c_x2 = 270;
	int c2_position = 70;

	CircleShape c2(c2_r);
	c2.setOrigin((c2_r), (c2_r));
	c2.setFillColor(sf::Color(128, 255, 128));
	c2.setPosition(c_x2, c2_position);

	int c3_r = 50;
	int c_x3 = 450;
	int c3_position = 130;

	CircleShape c3(c3_r);
	c3.setOrigin((c3_r), (c3_r));
	c3.setFillColor(sf::Color(145, 238, 231));
	c3.setPosition(c_x3, c3_position);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		c1_position = c1_position + 4;
		if (c1_position > height_window-c1_r)
		{
			c1_position = (height_window-c1_r);
		}
		c1.setPosition(c_x1, c1_position);

		c2_position = c2_position + 3;
		if (c2_position > height_window-c2_r)
		{
			c2_position = (height_window-c2_r);
		}
		c2.setPosition(c_x2, c2_position);

		c3_position = c3_position + 5;
		if (c3_position > height_window-c3_r)
		{
			c3_position = (height_window-c3_r);
		}
		c3.setPosition(c_x3, c3_position);


		window.clear(Color(68, 68, 68, 0));

		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.display();

		std::this_thread::sleep_for(5ms);


	}

	return 0;
}