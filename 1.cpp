//(A)Отгадай число
#include <iostream>
using namespace std;
int main() {
    int left = 0;
    int right = 1e6 + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        cout << mid << endl;
        string answ;
        cin >> answ;
        if (answ == ">=") {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << "! " << left << endl;
}

//(C)Построение аквариума
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long size, water;
        cin >> size >> water;
        vector < long long > koral(size);
        for (long long i = 0; i < size; i++) {
            cin >> koral[i];
        }
        sort(koral.begin(), koral.end());

        long long l = 1;
        long long r = 1e17;

        while (r - l > 1) {
            long long mid = (r + l) / 2;
            long long count_w = 0;
            for (long long i = 0; i < size; i++) {
                if (mid >= koral[i]) {
                    count_w += mid - koral[i];
                    if (count_w > water) break;
                }
            }
            if (count_w <= water) {
                l = mid;
            }
            else {
                r = mid;
            }

        }
        cout << l << "\n";
    }
}

//(I)Найдите точку экстремума
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long copy, time_p1, time_p2;
    cin >> copy >> time_p1 >> time_p2;

    if (copy == 1) {
        cout << min(time_p1, time_p2);
        return 0;
    }
    long long ost = copy - 1;
    long long l = 0;
    long long r = ost;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (mid * time_p1 < (ost - mid) * time_p2) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    long long timel = max(l * time_p1, (ost - l) * time_p2);
    long long timer = max(r * time_p1, (ost - r) * time_p2);
    cout << min(time_p1, time_p2) + min(timel, timer);
}

//(B) Одинокое число
#include <iostream>
using namespace std;

//запрос числа
int zapros(int id) {
    cout << "? " << id << endl;
    int a_id;
    cin >> a_id;
    return a_id;
}

int main() {
    int size;
    cin >> size;
    if (size == 1) {//если всего 1 элемент
        cout << "? " << 1 << endl;
        int a;
        cin >> a;
        cout << "! " << a << endl;
        return 0;
    }
    int l = 1;//идексация с 1 до размера
    int r = size;
    while (l < r) {
        int mid = (l + r) / 2;


        int znach_mid = zapros(mid);

        //индекс элемента с которым val_mid в паре
        int para_id;
        if (mid % 2 == 1) {
            para_id = mid + 1;
        }
        else {
            para_id = mid - 1;
        }
        int para = zapros(para_id);
        if (znach_mid == para) {
            if (mid % 2 == 1) {//если пара (mid ; mid+1)
                l = mid + 2;//левая граница за парой
            }
            else {// Если пара (mid-1 ; mid)
                l = mid + 1;
            }
        }
        else {//уникальный элемент находится в mid или левее
            r = mid;
        }
    }
    cout << "? " << l << endl;
    int eft;
    cin >> eft;
    cout << "! " << eft << endl;
}

//(L) Полей деревья
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int size;
        cin >> size;

        vector<long long> trees(size);
        long long max_trees = -1;
        for (int i = 0; i < size; i++) {
            cin >> trees[i];
            if (trees[i] > max_trees) max_trees = trees[i];
        }
        long long otv = -1;
        //сначала max = max_trees потом max = max_trees + 1, max_trees + 1 нужна если max_trees проблемная
        for (long long max : {max_trees, max_trees + 1}) {
            long long one = 0;//сколько нужно единиц
            long long two = 0;//сколько нужно двоек
            for (int i = 0; i < size; i++) {
                long long razn = max - trees[i];
                one += razn % 2;
                two += razn / 2;
            }
            //штука чтобы уравнять двойки
            if (two > one) {
                long long razn_3 = (two - one) / 3;//пример 9 двоек и 5 единиц
                one += razn_3 * 2;                 //получ. 8 двоек и 7 единиц
                two -= razn_3;
                //проверяем еще раз
                if (two - one == 2) {
                    one += 2;
                    two -= 1;
                }
            }
            long long day_now;
            if (one > two) {
                day_now = one * 2 - 1;//если единиц больше последний день будет нечетным
            }
            else {
                day_now = two * 2;
            }
            if (otv == -1 || day_now < otv) {//минимальный результат из двух вариантов
                otv = day_now;
            }
        }
        cout << otv << "\n";
    }
}

//(F)Фестиваль деревянных игрушек
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {

        int size;
        cin >> size;
        vector<int> home(size);
        for (int i = 0; i < size; i++) {
            cin >> home[i];
        }
        sort(home.begin(), home.end());

        int l = 0, r = 1e9, otv;
        while (l <= r) {
            int mid = (l + r) / 2;
            int count = 1;
            int now = home[0] + 2 * mid;
            for (int i = 1; i < size; i++) {
                if (home[i] > now) {
                    count++;
                    if (i < size) {
                        now = home[i] + 2 * mid;
                    }
                }
            }
            if (count <= 3) {
                otv = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << otv << "\n";
    }
}

//бин поиск 2  D рудольф и снежинки (сложная версия)
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
#define ull unsigned long long

int main() {
    int t;
    cin >> t;
    while (t--) {

        ull num_ver;
        cin >> num_ver;
        bool otv = false;
        for (int i = 3; i <= 64; i++) { // слои
            ull l = 2, r = 1e9; // бин поиск
            while (l <= r) {
                ull mid = (l + r) / 2; // к сейчас
                ull mid_step = 1; // к в степени 
                ull sum = 1; // все колво вершин
                bool pereborshil = false;
                for (int j = 1; j < i; j++) { // цикл для суммы всех точек текущего к
                    if (num_ver / mid < mid_step) { // проверка что следущая степень к не приводит к переполнению
                        pereborshil = true;
                        break;
                    }
                    mid_step *= mid;//вершин на текущем слое или же к в степени
                    sum += mid_step;
                    if (sum > num_ver) { // проверка переполн сумы
                        pereborshil = true;
                        break;
                    }
                }
                if (!pereborshil && sum == num_ver) {
                    otv = true;
                    break;
                }
                if (pereborshil || sum > num_ver) {
                    r = mid - 1;
                }// +- 1 чтобы с ума не сходил, бесконеч наверн если без него 
                else {
                    l = mid + 1;
                }
            }
            if (otv) {
                break;
            }
        }
        if (otv) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}