/*File : ͼ�����ϵͳ.cpp
 *---------------------------------
 *����ļ�����Books��ʵ��һ��ͼ�����ϵͳ
 *��֧�ִ����µ���Ŀ�����������鼮����ѯ�鼮�����ȵȲ���
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
	int x,y,Number,sgn;								//x,y���ڴ����ѯָ��			sgn���ڴ�������������
	double Price,money;
	Books * p = nullptr;
	string Name, Author, ISBN,s;
	cout << "						��ӭʹ��ͼ�����ϵͳ" << endl;
	do
	{
		cout<< "------------------------------------------------------------------------------------------------------------------------"
			<< "���ܲ˵���(����0���˳�)" << endl
			<< "[1] ��������Ŀ \t [2] ��ѯ \t [3] ���������鼮 \t [4]�޸ĵ���" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "���������²���(��#��ʾȱʡ,���������ۡ��ݲ�������ȱʡ��" << endl
				<< "�鼮������Ϊ��";
			cin >> Name;
			cout << "�鼮������Ϊ��";
			cin >> Author;
			if (Author == "#")
				Author = "";
			cout << "�鼮�ı��Ϊ��";
			cin >> ISBN;
			if (ISBN == "#")
				ISBN = "";
			cout << "�鼮�ĵ���Ϊ��";
			cin >> Price;
			cout << "�鼮������Ϊ��";
			cin >> Number;
			if (add_book(Name, Author, ISBN, Price, Number) == nullptr)
			{
				int x;							//�ֲ��������ڴ���ָ��
				cout << "�����ѹݲأ��Ƿ���ݶ������ݸ��²�����" << endl << "[1]�� \t [2]��" << endl;
				cin >> x;
				if (x == 1)
					reset(Name, Author, ISBN, Price, Number);
			}
			break;
		case 2:
			cout << "���������������鼮��ţ�";
			cin >> s;
			p = search(s);
			if (p == nullptr)
			{
				cout << "�ݲ���û�и��鼮" << endl;
				break;
			}
			cout << "��ѡ��" << endl << "[1]���� \t [2]���� \t [3]��� \t [4]���� \t [5]�ݲ��� \t [6]ȫ������" << endl;
			cin >> y;
			switch (y)
			{
			case 1:
				cout << "�鼮";
				p->show_name();
				cout << "������Ϊ��";
				p->show_name();
				cout << endl;
				break;
			case 2:
				cout << "�鼮";
				p->show_name();
				cout << "������Ϊ��";
				p->show_author();
				cout << endl;
				break;
			case 3:
				cout << "�鼮";
				p->show_name();
				cout << "�ı��Ϊ��";
				p->show_isbn();
				cout << endl;
				break;
			case 4:
				cout << "�鼮";
				p->show_name();
				cout << "�ĵ���Ϊ��";
				p->show_price();
				cout << endl;
				break;
			case 5:
				cout << "�鼮";
				p->show_name();
				cout << "�Ĺݲ���Ϊ��";
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
			cout << "���������������鼮��ţ�";
			cin >> s;
			p = search(s);
			if (p == nullptr)
			{
				cout << "�ݲ���û�и��鼮" << endl;
				break;
			}
			cout << "��ѡ���������������" << endl;
			cout << "[1]����\t[2]����" << endl;
			cin >> sgn;
			sgn *= 2;
			sgn -= 3;
			sgn = -sgn;
			cout << "������������";
			cin >> Number;
			money = p->change_number(sgn*Number);
			if (money)
			{
				if (sgn > 0)
					cout << "�˴ι��򻨷�" << money << "Ԫ��" << endl;
				else
					cout << "�˴γ��ۻ��" << -money << "Ԫ��" << endl;
			}
			cout << endl;
			break;
		case 4:
			cout << "���������������鼮��ţ�";
			cin >> s;
			p = search(s);
			if (p == nullptr)
			{
				cout << "�ݲ���û�и��鼮" << endl;
				break;
			}
			cout << "�������µĵ��ۣ�";
			cin >> Price;
			p->reset_price(Price);
			cout << "��������ɹ����������鼮";
			p->show_name();
			cout << "�Ĳ�����" << endl << *p;
			break;
		default:
			break;
		}
	} while (x != 0);
	clear();
	return 0;
}