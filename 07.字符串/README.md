## 0x00 字符串
字符串可以看成字符组成的数组，字符串是程序里需要经常处理的数据类型，因此有很多针对字符串处理的题目。  

## 0x01 字符串比较
判断两个字符串包含的字符是否相同。  
可以用哈希表或者数组统计两个字符串中每个字符出现的频次，若频次相同，则说明他们包含的字符完全相同。  
```C++
bool isAnagram(string s,string t) {
    if(s.length() != t.length()) {
        return false;
    }
    vector<int> counts(26,0);
    for(int i=0;i<s.length();i++) {
        ++counts[s[i]-'a'];
        --counts[t[i]-'a'];
    }
    for(int i=0;i<counts.size();i++) {
        if(counts[i]) {
            return false;
        }
    }
    return true;
}
```
关于测试用例：
```C++
string s1 = "listen";
string t1 = "silent";
bool result1 = isAnagram(s1, t1);
cout << "Test Case 1 - Result: " << (result1 ? "True" : "False") << endl;
```

## 0x02 判断两个字符串是否同构
同构的含义是可以把一个字符串的某些相同字符转换成另一些相同的字符，使两个字符产相同，且两种不同的字符，不能被转换成同一种字符。  

可以把问题转化一下：记录两个字符串中相同位置的字符第一次出现的位置，如果两个字符串中相同位置的字符与他们第一次出现的位置一样，则两个字符串同构。  
以 paper 和 title 举例，假设我们遍历到第三个字符 “p” 和 “t” 时，发现他们第一次出现的位置都在第一个字符，说明字符串遍历到目前位置满足同构。  
```C++
bool isIsomorphic(string s,string t) {
    vector<int> s_index(256,0),t_index(256,0);
    if(s.length()!=t.length()) {
        return false;
    }
    for(int i=0;i<s.length();i++) {
        if(s_index[s[i]] != t_index[t[i]]) {
            return false;
        }
        s_index[s[i]] = t_index[t[i]] = i+1;
    }
    return true;
}

int main() {
    string s="paper22",t="title11f";
    bool y = isIsomorphic(s,t);
    cout<<y<<endl;
    return 0;
}
```
如果没有规定好传入两个长度相等的字符串，需要先判断两个字符串长度是否相等，不然t比s长一位也会返回 true 。  

## 0x03 求回文子字符串个数
题目描述：给定一个字符，求其中有多少个回文子字符串（左右对称），最后输出字字符串个数。  
示例：string="aaa" 6个回文字符串分别是 “a”  “a”  “a”  “aa”  “aa”  “aaa”   
题解：可以从字符串的每个位置开始，向左向右延长，判断存在多少以当前位置为中轴的字符串。注意需要把奇数长度和偶数长度分开讨论。
```C++ 
int extendSubstrings(string s,int l,int r) {
    int count=0;
    while(l>=0 && r<s.length() && s[l]==s[r]) {
        l--;
        r++;
        ++count;
    }
    return count;
}

int countSubstrings(string s) {
    int counts=0;
    for(int i=0;i<s.length();i++) {
        counts+=extendSubstrings(s,i,i);//计算奇数长的的回文字符串
        counts+=extendSubstrings(s,i,i+1);//计算偶数长度的回文字符串
    }
    return counts;
}
```