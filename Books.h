/*File : Books.h
 *---------------------------------
 *����ļ�����Ϊͼ�����ϵͳ����Books��
 */
#ifndef Books_H_
#define Books_H_
#include <string>
#include <iostream>
class Books
{
	std::string ISBN;						//ͼ��Ĺ��ʱ�׼���
	std::string Author, Name;				//ͼ������ߺ�����
	int Number;								//ͼ��Ĺݲ���
	double Price;							//ͼ��ĵ���
	Books * Next, * Pre;					//ͼ�����ϵͳ��ʵ�ֻ���˫����
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
	Books * search(const std::string &s);										//��this����ʼ����
	friend Books * search(const std::string &s);								//ͨ���������ݱ�׼������أ����ṩ�������������ߵ�����
	friend Books * search(const std::string &s, Books * p);						//�ṩ��ָ��λ�ÿ�ʼ������
	friend Books * search(const std::string &n, std::string &a);				//�����������������ߵ�����
	friend Books * add_book(const std::string & Na = "", const std::string & A = "", const std::string & I = "", const double  P = 0, const int  Num = 0);
	friend Books * reset(const std::string & Na = "", const std::string & A = "", const std::string & I = "", const double  P = 0, const int  Num = 0);
};
#endif