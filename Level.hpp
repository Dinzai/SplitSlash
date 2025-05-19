#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

/*


MIT Licence
Author -> Brett Rogers

Simple Grid Based Level Generator






*/

namespace Dinzai
{

	struct GridChunk
	{

		GridChunk()
		{
			gridChunk.setSize(sf::Vector2f(10, 10));
			gridChunk.setFillColor(sf::Color::Transparent);
			gridChunk.setOutlineColor(sf::Color::White);
			gridChunk.setOutlineThickness(1.2);
		}

		sf::RectangleShape gridChunk;

	};

	struct PhysicsObject
	{

		PhysicsObject()
		{
			shape.setFillColor(sf::Color::Blue);
			shape.setSize(sf::Vector2f(10, 10));
		}

		void Drawable(sf::RenderWindow& window)
		{
			window.draw(shape);
		}

		sf::RectangleShape shape;

	};


	struct WorldGrid
	{


		WorldGrid()
		{

		}

		void MakeGrid(int worldWidth, int worldHeight, float offset)
		{
			for (int i = 0; i < worldWidth; i++)
			{
				for (int j = 0; j < worldHeight; j++)
				{
					GridChunk* chunk = new GridChunk();
					chunk->gridChunk.setPosition(i * chunk->gridChunk.getSize().x + offset, j * chunk->gridChunk.getSize().y + offset);
					chunks.push_back(chunk);
				}
			}

			std::cout << "the size of the World Grid is: " << chunks.size() << '\n';

		}


		void DrawGrid(sf::RenderWindow& window)
		{
			for (GridChunk* c : chunks)
			{
				window.draw(c->gridChunk);
			}
		}

		std::vector<GridChunk*> chunks;

	};


	struct Bucket
	{

		Bucket()
		{

		}


		void AddObject(PhysicsObject* temp)
		{
			allObj.push_back(temp);
		}


		void Drawable(sf::RenderWindow& window)
		{
			for (PhysicsObject* o : allObj)
			{
				o->Drawable(window);
			}

		}

		std::vector<PhysicsObject*> allObj;
	};

	struct Level
	{


		Level()
		{

		}


		void GenLevel(Bucket* b, int worldWidth, float offset)
		{
			for (int z = 0; z < level.size(); z++)
			{
				if (level[z] == 1)
				{
					int x = z % worldWidth;
					int y = z / worldWidth;

					PhysicsObject* obj = new PhysicsObject();
					obj->shape.setPosition(sf::Vector2f(x * obj->shape.getSize().x + offset, y * obj->shape.getSize().y + offset));
					b->AddObject(obj);
				}

			}
		}

		std::vector<int> level;



	};
}