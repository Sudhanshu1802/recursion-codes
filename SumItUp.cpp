#include<iostream>
using namespace std;
int main() {

  char ch;

  while (true)
  {
    cin >> ch;
    int n1, n2;

    if (ch == '+')
    { cin >> n1 >> n2;
      cout << long (n1 + n2) << endl;
    }

    else if (ch == '-')
    { cin >> n1 >> n2;
      cout << long (n1 - n2);
    }

    else if (ch == '*')
    { cin >> n1 >> n2;
      cout << long (n1 * n2) << endl;
    }

    else if (ch == '/')
    { cin >> n1 >> n2;

      if (n2 != 0)
      {cout << int (n1 / n2) << endl;}
      else if (n2 == 0) return 0;
    }

    else if (ch == '%')
    { cin >> n1 >> n2;
      if (n2 != 0)
      { cout << long (n1 % n2) << endl;}
      else if (n2 == 0) return 0;
    }
    else if (ch == 'X' || ch == 'x') break ;

    else cout << "Invalid Operation. Try Again." << endl;
  }

}