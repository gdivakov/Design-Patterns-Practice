#pragma once
#include <iostream>
#include <map>
#include <string>

void render(int x, int y, int color, int texture)
{
	std::cout
		<< "Place tree: (x: " << x
		<< ", y: " << y
		<< ", color: " << color
		<< ", texture: " << texture
		<< ")"
	<< std::endl;
}

// Flyweight
class TreeType
{
private:
	int color;
	int texture;
public:
	TreeType(int p_color, int p_texture) : color(p_color), texture(p_texture) {};

	void placeTree(int x, int y) { render(x, y, color, texture); };
};

// Flyweight factory
class TreeFactory
{
public:
	typedef std::map<std::string, TreeType*> TreeTypes;

	static TreeType* getTreeType(int color, int texture)
	{
		std::string key = std::to_string(color) + "+" + std::to_string(texture);

		if (!cache[key])
		{
			cache[key] = new TreeType(color, texture);
		}

		return cache[key];
	};

	static void free() {
		std::cout << "cachedFlyweights.size(): " << cache.size() << std::endl;

		for (auto& el : cache)
		{
			delete el.second;
		}

		cache.clear();
	};
private:
	static TreeTypes cache;
};

TreeFactory::TreeTypes TreeFactory::cache = {};

// Context
class Tree
{
private:
	TreeType* type;
	int x, y;
public:
	Tree(int p_x, int p_y, int color, int texture) : x(p_x), y(p_y)
	{
		type = TreeFactory::getTreeType(color, texture);
	};

	void placeTree() { type->placeTree(x, y); };
};