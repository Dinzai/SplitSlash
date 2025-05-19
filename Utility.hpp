#include "Split.hpp"
#include "Level.hpp"



/*

MIT Licence
Author -> Brett Rogers



*/


struct LUtilty 
{

	LUtilty()
	{
		b = new Dinzai::Bucket();
		w = new Dinzai::WorldGrid();
	}
private:

	~LUtilty()
	{
		delete b;
	}
public:


	void LoadGrid() 
	{
		w->MakeGrid(20, 15, 50);
	}

	void LoadLevel(std::string data, char splitChar) 
	{
		stringSpliter.Do(data, splitChar);
		generator.level = stringSpliter.ConverToInt(stringSpliter.goal);
	}

	void CreateLevel() 
	{
		generator.GenLevel(b, 20, 50);
	}

	void DisplayLevel(sf::RenderWindow& window) 
	{
		b->Drawable(window);
	}

	void DisplayGrid(sf::RenderWindow& window)
	{
		w->DrawGrid(window);
	}

private:
	Dinzai::HelperFunctions stringSpliter;
	Dinzai::Level generator;
	Dinzai::Bucket* b;
	Dinzai::WorldGrid* w;

};
