## 0x00 哈希表
哈希表，又称为散列表，使用 O(n) 的空间复杂度存储数据，通过哈希函数映射位置，从而实现近似 O(1) 时间复杂度的插入、查找、删除等操作。  
C++ 中的哈希集合为 unordered_set ,可以查找元素是否在集合中。如果需要同时存储键和值，则需要用 unordered_map ，可以用来统计频率，记录内容等。

## 0x01 template\<typename T>
template\<typename T> 是 C++ 中 模板编程 的一种声明方式，允许我们编写可以处理不同类型数据的代码，而不需要重复编写多份代码。它的作用是让程序员能够定义 通用的类、函数或结构，并在实例化时根据需要指定类型。  
template关键字：模板定义关键字，告诉编译器需要定义一个模板。  
typename T ：T是一个模板参数，表示一个占位符。T可以是任意类型，他将在类或函数实例化时由用户指定的实际类型来替代。  
函数模板：  
```C++
template <typename T>
T add(T a, T b) {
    return a + b;
}
```
这个add函数是一个函数模板，它可以接受任意类型 T 的参数并返回 T 的结果。在使用时，编译器会根据传入参数的类型推导出T的实际类型。使用方法如下：  
```C++
int result1 = add(3, 5);        // 这里 T 被推导为 int
double result2 = add(3.2, 4.5); // 这里 T 被推导为 double
```
类模板：  
```C++
template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() const { return value; }
};
```
在Box类模板中，T可以是任意类型。当我们创建一个Box对象时，可以指定T是什么类型：  
```C++
Box<int> intBox(5);        // 这里 T 被指定为 int
Box<double> doubleBox(3.14); // 这里 T 被指定为 double
```

## 0x02 哈希表结构


## 0x03 TwoSum两数之和
利用哈希表存储遍历过的值和他们的位置，每次遍历到位置 i 的时候，查找哈希表里是否存在 target - nums \[i] ，若存在，则说明这两个值的和为 target。  
```C++
vector<int> twoSum(vector<int>& nums,int target) {
    //hash表，键是数组中的数值，值是该数值的索引
    unordered_map<int,int> hash;
    vector<int> ans;
    //i是当前数组的索引，nums[i]是当前的数值
    for(int i=0;i<nums.size();i++) {
        int num = nums[i];
        //使用auto简化代码，不然类型名既复杂又很长
        //unordered_map<int, int>::iterator pos = hash.find(target - num);
        //pos是一个迭代器类型
        auto pos = hash.find(target-num);
        if(pos == hash.end()) {
            hash[num]=i;
        }else {
            //pos是迭代器类型，返回 unordered_map<int, int>
            //first对应键，second对应这个键的值
            ans.push_back(pos->second);
            ans.push_back(i);
            break;
        }
    }
    return ans;
}
```