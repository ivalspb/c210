#pragma once

template <typename Container>
void print(Container c)
{
	while (!c.empty())
		std::cout << c.pop()<<" ";
}