#include <iostream> 
#include "test.pb.h" // 引入编译生成的头文件 
using namespace std; 
 
int main() { 
 string people_str; 
 // 序列化
 { 
 // .proto 文件声明的 package，通过 protoc 编译后，会为编译生成的C++代码声明同名的命名空间
 // 其范围是在.proto 文件中定义的内容
 contacts::PeopleInfo people; 
 people.set_age(20); 
 people.set_name("张珊"); 
 // 调用序列化方法，将序列化后的二进制序列存入 string 中
 if (!people.SerializeToString(&people_str)) { 
 cout << "序列化联系人失败." << endl; 
 } 
 // 打印序列化结果
 cout << "序列化后的 people_str: " << people_str.size() << 
endl; 
 } 
 // 反序列化 
 { 
 contacts::PeopleInfo people; 
 // 调用反序列化方法，读取 string 中存放的二进制序列，并反序列化出对象
 if (!people.ParseFromString(people_str)) { 
 cout << "反序列化出联系人失败." << endl; 
 } 
 // 打印结果
 cout << "Parse age: " << people.age() << endl; 
 cout << "Parse name: " << people.name() << endl; 
 } 
 return 0;
}