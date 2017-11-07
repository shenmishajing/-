/*File : Books.cpp
 *---------------------------------
 *这个文件为Books类提供具体实现
 */
#include "Books.h"
#include <iostream>
#include <windows.h>

Books * Books::Head = nullptr, * Books::Tail = nullptr;

Books::Books(const std::string & Na, const std::string & A, const std::string & I, const double P, const int Num)
{
	if (P < 0)
	{
		std::cout << "价格不能为负数" << std::endl;
		return;
	}
	if (Num < 0)
	{
		std::cout << "馆藏量不能为负数" << std::endl;
		return;
	}
	if (Books::Head == nullptr)
	{
		Books::Head = this;
		Pre = nullptr;
	}
	else
	{
		Pre = Books::Tail;
		Books::Tail->Next = this;
	}
	Books::Tail = this;
	Next = nullptr;
	Name = Na;
	Author = A;
	ISBN = I;
	Price = P;
	Number = Num;
}

Books::~Books()
{
	if ((Books::Head == this) && (Books::Tail == this))
	{
		Books::Head = Books::Tail = nullptr;
		return;
	}
	if (Books::Head == this)
	{
		Books::Head = this->Next;
		this->Next->Pre = nullptr;
	}
	else
		if (Books::Tail == this)
		{
			Books::Tail = this->Pre;
			this->Pre->Next = nullptr;
		}
		else
		{
			this->Pre->Next = Next;
			this->Next->Pre = Pre;
		}
}

double Books::change_number(int n)
{
	double money = n * Price;
	Number += n;
	if (Number < 0)
	{
		std::cout << "不能卖出超过余量的书籍，操作已取消。" << std::endl;
		Number -= n;
		return 0;
	}
	else if (Number == 0)
		delete this;
	return money;
}

void Books::show() const
{
	std::cout << "书籍的名称为："<< Name << std::endl;
	std::cout << "书籍的作者为："<< Author << std::endl;
	std::cout << "书籍的编号为："<< ISBN << std::endl;
	std::cout << "书籍的单价为："<< Price << std::endl;
	std::cout << "书籍的数量为："<< Number << std::endl;
}

Books * Books::search(const std::string & s)
{
	Books * p = this;
	while (p != Books::Tail)
	{
		if ((p->Name == s) || (p->ISBN == s)) break;
		p = p->Next;
	}
	if ((p->Name == s) || (p->ISBN == s))
		return p;
	else
		return nullptr;
}

std::ostream & operator<<(std::ostream & os, Books & b)
{
	std::cout << "书籍的名称为：" << b.Name << std::endl;
	std::cout << "书籍的作者为：" << b.Author << std::endl;
	std::cout << "书籍的编号为：" << b.ISBN << std::endl;
	std::cout << "书籍的单价为：" << b.Price << std::endl;
	std::cout << "书籍的数量为：" << b.Number << std::endl;
	return os;
}

void clear()
{
	while (Books::Head != nullptr)
		delete Books::Head;
}

Books * search(const std::string & s)
{
	if (Books::Head == nullptr)
		return nullptr;
	Books * p = Books::Head;
	while (p != Books::Tail)
	{
		if ((p->Name == s) || (p->ISBN == s)) break;
		p = p->Next;
	}
	if ((p->Name == s) || (p->ISBN == s))
		return p;
	else
		return nullptr;
}

Books * search(const std::string & s, Books * q)
{
	Books * p = q;
	while (p != Books::Tail)
	{
		if ((p->Name == s) || (p->ISBN == s)) break;
		p = p->Next;
	}
	if ((p->Name == s) || (p->ISBN == s))
		return p;
	else
		return nullptr;
}

Books * search(const std::string & n, std::string & a)
{
	Books * p = nullptr;
	while (p != Books::Tail)
	{
		p = p->Next;
		if ((p->Name == n) && (p->Author == a)) break;
	}
	return nullptr;
}

Books * add_book(const std::string & Na, const std::string & A, const std::string & I, const double P, const int Num)
{
	Books * p;
	if ((I != "")&&(search(I) != nullptr))
		return nullptr;
	while ((p = new Books(Na, A, I, P, Num)) == nullptr)
		Sleep(1000);
	return p;
}

Books * reset(const std::string & Na, const std::string & A, const std::string & I, const double P, const int Num)
{
	Books * p = search(I);
	p->Author = A;
	p->Name = Na;
	p->Price = P;
	p->Number = Num;
	return nullptr;
}
