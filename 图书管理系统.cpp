/*File : 图书管理系统.cpp
 *---------------------------------
 *这个文件利用Books类实现一个图书管理系统
 *它支持创建新的书目，买入卖出书籍，查询书籍余量等等操作
 */
#include <iostream>
#include <windows.h>
#include "Books.h"
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	int x,y,Number,sgn;								//x,y用于储存查询指令			sgn用于储存买入与卖出
	double Price,money;
	Books * p = nullptr;
	string Name, Author, ISBN,s;
	cout << "						欢迎使用图书管理系统" << endl;
	do
	{
		cout<< "------------------------------------------------------------------------------------------------------------------------"
			<< "功能菜单：(输入0以退出)" << endl
			<< "[1] 创建新书目 \t [2] 查询 \t [3] 买入卖出书籍 \t [4]修改单价" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "请输入以下参数(用#表示缺省,书名、单价、馆藏量不可缺省）" << endl
				<< "书籍的名称为：";
			cin >> Name;
			cout << "书籍的作者为：";
			cin >> Author;
			if (Author == "#")
				Author = "";
			cout << "书籍的编号为：";
			cin >> ISBN;
			if (ISBN == "#")
				ISBN = "";
			cout << "书籍的单价为：";
			cin >> Price;
			cout << "书籍的数量为：";
			cin >> Number;
			if (add_book(Name, Author, ISBN, Price, Number) == nullptr)
			{
				int x;							//局部变量用于储存指令
				cout << "该书已馆藏，是否根据读入数据更新参数？" << endl << "[1]是 \t [2]否" << endl;
				cin >> x;
				if (x == 1)
					reset(Name, Author, ISBN, Price, Number);
			}
			break;
		case 2:
			cout << "请输入书名或者书籍编号：";
			cin >> s;
			p = search(s);
			if (p == nullptr)
			{
				cout << "馆藏中没有该书籍" << endl;
				break;
			}
			cout << "请选择：" << endl << "[1]名称 \t [2]作者 \t [3]编号 \t [4]单价 \t [5]馆藏量 \t [6]全部参数" << endl;
			cin >> y;
			switch (y)
			{
			case 1:
				cout << "书籍";
				p->show_name();
				cout << "的名称为：";
				p->show_name();
				cout << endl;
				break;
			case 2:
				cout << "书籍";
				p->show_name();
				cout << "的作者为：";
				p->show_author();
				cout << endl;
				break;
			case 3:
				cout << "书籍";
				p->show_name();
				cout << "的编号为：";
				p->show_isbn();
				cout << endl;
				break;
			case 4:
				cout << "书籍";
				p->show_name();
				cout << "的单价为：";
				p->show_price();
				cout << endl;
				break;
			case 5:
				cout << "书籍";
				p->show_name();
				cout << "的馆藏量为：";
				p->show_number();
				cout << endl;
				break;
			case 6:
				cout << *p;
				break;
			default:
				break;
			}
			break;
		case 3:
			cout << "请输入书名或者书籍编号：";
			cin >> s;
			p = search(s);
			if (p == nullptr)
			{
				cout << "馆藏中没有该书籍" << endl;
				break;
			}
			cout << "请选择买入或者卖出：" << endl;
			cout << "[1]买入\t[2]卖出" << endl;
			cin >> sgn;
			sgn *= 2;
			sgn -= 3;
			sgn = -sgn;
			cout << "请输入数量：";
			cin >> Number;
			money = p->change_number(sgn*Number);
			if (money)
			{
				if (sgn > 0)
					cout << "此次购买花费" << money << "元。" << endl;
				else
					cout << "此次出售获得" << -money << "元。" << endl;
			}
			cout << endl;
			break;
		case 4:
			cout << "请输入书名或者书籍编号：";
			cin >> s;
			p = search(s);
			if (p == nullptr)
			{
				cout << "馆藏中没有该书籍" << endl;
				break;
			}
			cout << "请输入新的单价：";
			cin >> Price;
			p->reset_price(Price);
			cout << "单价重设成功，以下是书籍";
			p->show_name();
			cout << "的参数：" << endl << *p;
			break;
		default:
			break;
		}
	} while (x != 0);
	clear();
	return 0;
}