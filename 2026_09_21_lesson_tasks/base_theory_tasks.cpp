#include <clocale>
#include <iostream>

void func(char msg[], const char const_msg[], const char* const super_const_msg);

int main() {
    const char space = ' ';

    {
        std::cout << "Деление чисел" << std::endl;
        std::cout << "5 / 9 = " << 5 / 9 << std::endl;
        std::cout << "5.0 / 9 = " << 5.0 / 9 << std::endl;

        int a = 1;
        int b = 5;
        std::cout << "a / b = " << a / b << std::endl;

        std::cout << std::endl << std::endl;
    }

    {
        std::cout << "Указатели. Основа" << std::endl;
        int x = 5;
        int* xptr = &x;
        std::cout << "xptr = " << xptr << "; *xptr = " << *xptr << std::endl;

        int* yptr = xptr;
        *yptr = 10;
        std::cout << "x = " << x << "; *xptr = " << *xptr << std::endl;
        std::cout << std::endl;

        std::cout << "Приоритет операций" << std::endl;
        int y1 = *xptr + 1;
        int y2 = *(xptr + 1);
        std::cout << "y1 = " << y1 << "; y2 = " << y2 << std::endl;

        *xptr += 1;
        std::cout << "\"*xptr += 1\" = " << *xptr << std::endl;
        std::cout << std::endl;

        std::cout << "Префиксный и постфиксный инкремент" << std::endl;
        *xptr = 5;
        std::cout << "x = " << x << std::endl;
        std::cout << "++x = " << ++x << std::endl;
        std::cout << "x++ = " << x++ << std::endl;

        std::cout << "++*xptr = " << ++ * xptr << std::endl;
        //std::cout << "*xptr++ = " << *xptr++ << std::endl;
        std::cout << "(*xptr)++ = " << (*xptr)++ << std::endl;

        std::cout << std::endl << std::endl;
    }

    {
        int a = 1, b = 2;
        std::swap(a, b);
        std::cout << "a = " << a << "; b = " << b << std::endl;
        std::cout << std::endl;

        std::cout << "Указатели и массивы" << std::endl;
        
        int arr[3] = { 1, 10, 20 };
        std::cout << "Элементы массива:";
        for (int x : arr) {
            std::cout << space << x;
        }
        std::cout << std::endl;

        int* ptr_arr = &arr[0];

        std::cout << "sizeof(arr) = " << sizeof(arr) << std::endl;
        std::cout << "sizeof(ptr_arr) = " << sizeof(ptr_arr) << std::endl;
        std::cout << std::endl;

        std::cout << "Вспоминаем что такое постфиксный инкремент" << std::endl;
        std::cout << "*ptr_arr++ = " << *ptr_arr++ << std::endl; 
        std::cout << "++*ptr_arr = " << ++*ptr_arr << std::endl;
        std::cout << "*++ptr_arr = " << *++ptr_arr << std::endl;
           
        std::cout << "*(ptr_arr + 1) = " << *(ptr_arr + 1) << std::endl;
        std::cout << "ptr_arr - &arr[0] = " << ptr_arr - &arr[0] << std::endl;
        //*(ptr_arr += 1) = 0;

        std::cout << std::endl << std::endl;
    }

    {
        std::cout << "Имя массива НЕ является переменной!!!" << std::endl;
        std::cout << "А указатель, выступающий в роли имени массива является переменной." << std::endl;
        std::cout << std::endl;

        int arr[] = {1, 2, 3, 4, 5, 6};
        std::cout << "Почему индексация у массивов начинается с 0?" << std::endl;
        std::cout << std::endl;

        std::cout << "Хитромудрёный пример:" << std::endl;
        int example_1 = 3[arr - 1] - arr[3] + (arr - 1)[5];
        std::cout << "3[arr - 1] - arr[3] + (arr - 1)[5] = " << example_1 << std::endl;

        std::cout << std::endl << std::endl;
    }

    {
        char msg[] = "Я массив! А тот, что в следующей строке, - всего лишь указатель на меня.";
        const char* ptr_msg = "Увы, я всего лишь указатель. И делайте со мной любые (допустимые) операции :(";
    }

    {
        char msg[] = "Мне можно менять только значения!";
        const char const_value_msg[] = "А меня вообще никак нельзя менять!";

        msg[0] = 'Б';
        //const_value_msg[0] = 'Б';

        //const_value_msg = msg;
        //msg = const_value_msg;
    }

    {
        //char* error_msg = "Меня константу хотят присвоить обычной переменной!";
        const char* const_value_msg = "Мне нельзя менять значения, но можно присвоить адрес на другую строку!";
        const char* const super_const_msg = "А меня вообще никак нельзя менять!";

        //const_value_msg[0] = 'Б';
        const_value_msg = super_const_msg;
        //super_const_msg = const_value_msg;
    }

    {
        char msg[] = "Я в функцию пойду как указатель на первый элемент строки. У меня можно все менять :(";
        const char const_msg[] = "Я тоже в функцию пойду как указатель на первый элемент строки :(, "
            "но с неизменяемыми значениями! :)";
        const char* const super_const_msg = "А я неизменяемый указатель на неизменяемые данные! Ха! Ха!";
        func(msg, const_msg, super_const_msg);
    }

    {
        std::cout << "Массив единиц элегантно превращается в: ";
        char carr[] = { 1,1,1,1, 1,1,1,1, 1,1,1,1 };
        *((int*)carr + 2) = 0;
        int i = 0;
        for (int x : carr) {
            std::cout << space << x;
            i++;
        }
        std::cout << "; i = " << i << std::endl;
        
        std::cout << std::endl << std::endl;
    }

    return 0;
}

void func(char msg[], const char const_msg[], const char* const super_const_msg) {

}
