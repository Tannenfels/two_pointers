#include <iostream>
#include <cstdlib>

struct result{
    int nums[2];
    bool isValid = false;
};

int comp(const int *i, const int *j)
{
    return *i - *j;
}

result* xseek(int* a, int len, int x)
{
    auto res = new result;
    int* b = a + --len;
    do {
        if((*a + *b) == x) {
            res->nums[0] = *a;
            res->nums[1] = *b;
            res->isValid = true;
            return res;
        } else if((*a + *b) < x) {
            a++;
        } else if((*a + *b) > x) {
            b--;
        }
    } while (a != b);

    return res;
}

int main()
{
    int x = 0;
    int len;
    std::cout << "Enter target value:" << std::endl;
    std::cin >> x;

    std::string input;
    std::cout << "Enter array size (default = 5):" << std::endl;
    std::cin >> len;
    if(!len) {
        len = 5;
    }

    int arr[len];

    for (int i = 0; i < len; i++) {
        arr[i] = rand() % len + 1;
    }

    std::qsort(arr, len, sizeof(int), (int(*) (const void *, const void *)) comp);

    int* a = arr;
    auto res = xseek(a, len, x);
    if(res->isValid) {
        std::cout << res->nums[0] << ',' << res->nums[1] << std::endl;
    } else {
        std::cout << "Array does not contain target value." << std::endl;
    }
    std::cout << "Array was:" << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
