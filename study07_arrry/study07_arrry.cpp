/*
* 名称：数组测试
* 
* 收获：
* 1、数组传入到函数中的时候，因为传入的只有一个首地址，sizeof无效了
*   但是可以加入一个长度参数，传这个参数时用sizeof计算
* 2、无论是 *array 、 array[] 还是 array[5] 作为参数，实际效果都是一样的
*   也就是说就函数而言，数组的长度是无关紧要的，因为 C++ 不会对形式参数执行边界检查。
* 
*/

#include <iostream>

//#define ARRAY_AS_RETURN_TEST
//#define STRING_TEST

#ifdef ARRAY_AS_RETURN_TEST

#include <ctime>
#include <cstdlib>

#endif // ARRAY_AS_RETURN_TEST

#ifdef STRING_TEST
#include <string>
#endif // STRING_TEST


void dyadic_array_test(void);
void array_pointer_test(void);
void array_as_parameters_test_1(int *array,int lenth);
void array_as_parameters_test_2(int array[5]);
void array_as_parameters_test_3(int array[]);
int* array_as_return_test(void);
void string_test(void);


int main()
{
    int test_array[10] = { 0,1,2,3,4,5,6,7,8,9 };

    //dyadic_array_test();
    //array_pointer_test();

    //array_as_parameters_test_1(test_array, sizeof(test_array) / sizeof(test_array[0]));
    //array_as_parameters_test_2(test_array);
    //array_as_parameters_test_3(test_array);

#ifdef ARRAY_AS_RETURN_TEST

    int* p = array_as_return_test();
    for (int i = 0; i < *p; i++)
    {
        std::cout << "array[" << i << "] = " << *(p + i) << std::endl;
    }

#endif // ARRAY_AS_RETURN_TEST

#ifdef STRING_TEST
    string_test();
#endif // STRING_TEST


    std::cout << "\n测试完成\n";
    return 0;
}

void dyadic_array_test(void)
{
    std::cout << "创建二维数组并初始化---" << std::endl;

    double test_array[8][8] = { 0 };

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << "array[" << i << "][" << j << "] = " << test_array[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            test_array[i][j] = (double)(i + j * 0.1);
        }
    }
    
    std::cout << "修改后：" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << "array[" << i << "][" << j << "] = " << test_array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void array_pointer_test(void)
{
    std::cout << "一维数组测试:" << std::endl;

    int test_array_1[6] = { 0,1,2,3,4,5 };

    for (int i = 0; i < 6; i++)
    {
        std::cout << "array[" << i << "] =\t" << test_array_1[i] << '\t';
        std::cout << "*(array+" << i << ") =\t" << *(test_array_1 + i) << '\n';
    }
   
    std::cout << "二维数组测试:" << std::endl;

    int test_array_2[6][6] = { 0 };

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            test_array_2[i][j] = i * 10 + j;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << "array[i]j[] = " << test_array_2[i][j] << '\t';
            std::cout << "*(*(array+i)+j) = " << *(*(test_array_2 + i) + j) << '\t';
            std::cout << "array = " << test_array_2 << '\t';
            std::cout << "array + i = " << (test_array_2 + i) << '\t';
            std::cout << "*(array + i)+j = " << (*(test_array_2 + i) + j) << '\n';
        }
    }

}

void array_as_parameters_test_1(int* array,int lenth)
{
    std::cout << "只通过数组指针传值后读取到以下值：" << std::endl;
    
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)      //测试结果说明sizeof在这里失效了
    {
        std::cout << "array["<<i<<"] = "<<array[i] << std::endl;
    }

    std::cout << "如果知道数组长度，读取到以下值：" << std::endl;

    for (int i = 0; i < lenth; i++)     
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
}

void array_as_parameters_test_2(int array[5])
{
    std::cout << "只通过数组指针传值后读取到以下值：" << std::endl;

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)      //测试结果说明sizeof在这里失效了
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

    std::cout << "指定一个长度后可以读取：" << std::endl;
    for (int i = 0; i < 8; i++)                    //测试结果表面 array[] 和 array[5] 和 指针 的传值效果相同
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

}

void array_as_parameters_test_3(int array[])
{
    std::cout << "只通过数组指针传值后读取到以下值：" << std::endl;

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)      //测试结果说明sizeof在这里失效了
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

    std::cout << "指定一个长度后可以读取：" << std::endl;
    for (int i = 0; i < 8; i++)                    //测试结果表面 array[] 和 array[5] 和指针 的传值效果相同
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }

}

#ifdef ARRAY_AS_RETURN_TEST

int* array_as_return_test(void)
{
    static int retrn_array[10] = { 10 , 0 };

    srand((unsigned)time(NULL));

    for (int i = 1; i < retrn_array[0]; i++)
    {
        retrn_array[i] = rand();
        std::cout << "函数内报告：" << "retrn_array[i] = " << retrn_array[i] << std::endl;
    }

    return retrn_array;
}

#endif // ARRAY_AS_RETURN_TEST

#ifdef STRING_TEST
void string_test(void)
{
    std::cout << "正在初始化俩个字符串：" << std::endl;
    std::string test_string_1  = "hello ";
    std::string test_string_2  = "wolrd!";
    std::string test_string_3  = "";
    std::cout << "string_1 :" << test_string_1 << std::endl
        << "string_2 :" << test_string_2 << std::endl
        << "string_3 :" << test_string_3 << std::endl;
    std::cout << std::endl;

    std::cout << "string_3 = string_1" << std::endl;
    test_string_3 = test_string_1;
    std::cout << "string_3 = " << test_string_3 << std::endl;
    std::cout << std::endl;

    std::cout << "string_3 = string_1 + string_2" << std::endl;
    test_string_3 = test_string_1 + test_string_2;
    std::cout << "string_3 = " << test_string_3 << std::endl;
    std::cout << std::endl;

    if (test_string_1 < test_string_2)
    {
        std::cout << "string_1 < string_2";
    }
    else 
    {
        std::cout << "string_1 > string_2";
    }
    std::cout << std::endl << std::endl;

    std::cout << "string_1.size() = " << test_string_1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "string_1.find('o') = " << test_string_1.find('o') << std::endl;   
    std::cout << std::endl;

    std::cout << "string_1.find(\"ll\") = " << test_string_1.find("ll") << std::endl;
    std::cout << std::endl;

}
#endif // STRING_TEST
