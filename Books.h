/*File : Books.h
 *---------------------------------
 *这个文件用于为图书管理系统声明Books类
 */
#ifndef Books_H_
#define Books_H_
#include <string>
#include <iostream>
class Books
{
	std::string ISBN;						//图书的国际标准书号
	std::string Author, Name;				//图书的作者和书名
	int Number;								//图书的馆藏量
	double Price;							//图书的单价
	Books * Next, * Pre;					//图书管理系统的实现基于双链表
	static Books * Head, * Tail;
public:
	Books(const std::string & Na = "", const std::string & A = "", const std::string & I = "", const double  P = 0 , const int  Num = 0);
	~Books();
	void reset_price(double p) { Price = p;};
	double change_number(int n);
	void show() const;
	void show_name() const { std::cout << Name; }
	void show_author() const { std::cout << Author; }
	void show_isbn() const { std::cout << ISBN; }
	void show_price() const { std::cout << Price; }
	void show_number() const { std::cout << Number; }
	friend std::ostream & operator<<(std::ostream &os, Books & b);
	friend void clear();
	Books * search(const std::string &s);										//从this出开始查找
	friend Books * search(const std::string &s);								//通常用于依据标准书号搜素，亦提供依据书名或作者的搜素
	friend Books * search(const std::string &s, Books * p);						//提供从指定位置开始的搜素
	friend Books * search(const std::string &n, std::string &a);				//用于依据书名和作者的搜素
	friend Books * add_book(const std::string & Na = "", const std::string & A = "", const std::string & I = "", const double  P = 0, const int  Num = 0);
	friend Books * reset(const std::string & Na = "", const std::string & A = "", const std::string & I = "", const double  P = 0, const int  Num = 0);
};
#endif