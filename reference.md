# 语言手册
## 1.基础
### 1.1注释 
使用`#`可以注释一行代码。**nyx**不支持多行注释，对于多行需要重复`#`

### 1.2数据类型
**int**表示整数类型，如`3`,`100000`,`1024`

**double** 表示小数类型，如`3.1415926`,`2.232`，`4.4` 

**string** 表示字符串类型，如`"string"`,`"test"`,`""`。

**bool** 布尔类型，值域只有字面值`true`和`false`

**null** 空值类型，用于指示该变量不具有值，值域只有字面值`null`

**char** 字符类型，表示单个字符，如`'a'`,`'Y'`

**array** 数组类型，用于创建一个数组，数组元素可以是**任意类型**，如`[2.718,"hell",null,false,'u']`

**closure** 闭包类型，用于创建一个可以捕获外部自由变量的匿名函数。如
```
a = 10
add10 = func(){
    return a+10
}
```
### 1.3 变量
真不不敢想象没有变量的世界，我们得先介绍它。
`name = value`即定义名为**name**的变量，具有**value**值。
如果`name`是索引表达式，相应的就是更新数组索引值而不是添加它，也就是说，向数组中一个不存在的索引赋值是错误。
由于赋值是**表达式**而不是**语句**，所以它也可以出现在任何表达式可以出现的地方：
```nyx
print(ff=15&5|12) # print the result of 15&5|12, that is, 13
a = [1,3,4]
println(a) # print [1,3,4]
a[0] = 5
println(a) # print [5,3,4]
a = 1
a += 1
println(a==2)
a -= 3
println(a==-1)
a *= 4
println(a==-4)
a /= 2
println(a==-2)
a %= 2
println(a==0)
```

## 2.运算符
### 2.1 计算基石
`+,-,*,/,%`是计算的基石，所以没有不支持的道理。在**nyx**中四则运算的优先级和运算规则与其它语言无二：
```nyx
d = (3+2)*4+(6*5)-8/2+(3+2*(5-4))
c = -7
a = 3+2-5
b = 3+5*2%2
print(a,b,c,d)                 
q = (((((((((((((((((((1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1)+1
print(q)
```

### 2.2 特殊重载
除了数值类型外，`+`,`*`符号对一些类型还有特殊效果。

对两个字符串进行`+`运算得到的是拼接后的结果；
`*`表示N次重复字符串：
```nyx
print("hello,"+"world") # will print hello,world
print("test" * 3 )      # will print testtesttest
```
对数组进行`+`运算会将另一个操作数放入数组中:
```nyx
a = [1,2,'c']
b = a+[4,5]
println(b) # print [1,2,[4,5]]
println(3+[4,5]) # print [3,4,5]
println([3]+[4,5]) # print [[3],4,5]
```

### 2.3 逻辑运算
`&&`表示逻辑与运算，`||`表示逻辑或运算,`!`表示逻辑非运算。
。由于宿主语言是C++，这些逻辑运算也原生的具有[**短路求值**](https://en.wikipedia.org/wiki/Short-circuit_evaluation)特性。
```nyx
true&&false
false||true
!(false||false||false||(true||false))
```
### 2.4 条件运算
除了逻辑运算外，**nyx**也有完备的条件运算支持：`==`，`!=`，`>`，`>=`，`<`，`<=`:
```nyx
print((true&&false)==false)
print((false&&true)==false)
print((true||false)==true)
print((true||true)==true)
print(5>3 && 6<10 && (14>=13||13<=15))
```
另外值得注意的是`==`,`!=`运算符也支持`null`的条件比较:
+ `null==null`总是为`true`
+ `null!=null`总是为`false`。

### 2.5 位运算
位运算类似于C系语言：
```
# 位与
print(3&5) # 0011 & 0101 => 1

# 位或
print(4|66) # 00000100 & 01000010 => 70

# 位反
print(~43) # 00101011 =>11010100 => -44
```

## 3. 流程控制
## 3.1 if-else分支跳转
`if`语句可以根据条件进行分支跳转。单个`if`分支跳转和`if-else`分支跳转都是允许的：
```nyx
a = input()
if(a+1 == "whatsup"){
    print("fine")
}
b = 10
if(b <10){
    print("b is less than 10")
}else{
    print("b is greater equal than 10")
}
```

## 3.2 for与foreach循环
`for`循环类似于C系语言，由初始化表达式，条件表达式，后置表达式组成：
```nyx
for(i=2;i<x-1;i+=1){
    if(x%i==0){
        return false
    }
}
arr = [12,3,54,5,6]
for(i: arr){
}
```
`for`还有一种被称之为`foreach`的变体形式，它取列表中每个元素，赋值给指定变量：
```nyx
for(i : [4,5,6,'c',"foreach"]){
    println(i)
}
# range()为内置函数，返回元素为[1,2,...,9]的数组
for(t:range(10)){
    println(t)
}
```

## 3.3 while循环
**nyx**不打算在公共语言基础上标新立异，它的`while`做了与其他大多数语言一样的事情，即根据条件进行循环。
```nyx
a= 1
while(a<100){
    print("counter:"+a)
    a = a+1
}
```
## 3.4 break
`break`跳出最近一层循环：
```nyx
# 输出1-10
func upto10(){
    i=0
    while(true){
        if(i==10){
            break
        }
        print("up")
        i = i+1
    }
}
upto10()
```
## 3.5 continue
`continue`结束本次循环并继续下次循环(会对条件重新求值)：
```nyx
# 过滤奇数，输出limit以内的偶数
func filter_odd(limit)
{
    i = 1
    while(i<limit){
        if(i%2==1){
            i = i+1
            continue
        }
        print(i)
        i = i+1
    }
}

filter_odd(100)
```
## 3.6 模式匹配
[模式匹配](https://en.wikipedia.org/wiki/Pattern_matching)语句会将条件与匹配语句的条件从上至下逐一匹配：
```nyx
a = input()
match(a){
    3 => println("3")
    4 => {
        println("4")
        println("i don't like this number")
    }
    _ => println("any other number")
}
```
一旦匹配成功则进入分支执行相应动作。最后的`_`表示任意条件(**any**)，即只要出现改语句必定进入分支；另外如果只有一条语句可以省略`{}`
如果`match`语句没有条件表达式，就退化成了类似`if-else if-else`的多条件分支检查语句：
```nyx
# do nothing
match{}

# without condition expression in match statement
for(i=0;i<10;i+=1){
    match{
        i%5==0 =>println(i+" could be divided by 5")
        i%3==0 =>println(i+" could be divided by 3")
        i%2==0 =>println(i+" could be divided by 2")
        _=> println("mismatched!")
    }
}
```

## 4.函数
### 4.1 普通函数
函数几乎是现代编程语言最重要的抽象之一，在nyx可以使用`func`关键字引导函数定义：
```nyx
# 递归计算斐波那契
func fibonacci_rec(num){
    if(num<=2){
        return 1 
    }
    return fibonacci_rec(num-2) + fibonacci_rec(num-1)
}

# 判断是否为水仙花数
func isNarcissicsticNumber(num)
{
    old = num
    accumulate = 0
    while(0!=num){
        n = num%10
        accumulate = accumulate + n*n*n
        num = num/10
        
    }
    return accumulate==old
}
```
关键字`return`用于控制返回
```nyx
# 将字符串字符逐个转化为*字符
func toStar(str){
    result = ""
    i =0
    while(i<length(str)){
        result = result+"*"
        i = i+1
    }
    return result
}
```
这里没有魔法。

### 4.2 闭包
定义[闭包](https://en.wikipedia.org/wiki/Closure_(computer_programming))也是由关键字`func`引导，只是没有具体名字。但是需要注意，严格意义上的闭包并不是匿名函数，**lambda**和匿名函数可以做等价替换，而闭包指定义在闭合环境的任何函数，它可以引用局部变量和形参之外的自由变量。
```nyx
func weird(num){
    closure_arr = []
    for(i:range(num)){
        closure_arr += func(){
            return i
        }    
    }
    return closure_arr
}
for(closure:weird(3)){
    println(closure+" produces the result:"+closure())
}
# closure produces the result:2
# closure produces the result:2
# closure produces the result:2
```
对于只有一条语句的闭包，可以省略花括号`{}`使用匹配符号`=>`代替，这样可以使得代码更紧凑：
```nyx
func hof(f1,f2){
    return f1(f2)
}

res = hof(func(f1)=> return func() => return f1()+5 ,func()=>return 8)
println(res()==13)
```

## 5.内置函数
```nyx
# 接受任意数目的参数，向stdout输出;println会额外输出一个换行符
func print(a:any,b:any...)
func println(a:any,b:any...)

# 无参数。接受stdin输入并返回输入字符串
func input()

# 接受一个参数，返回一个字符串用以表示实参类型
func typeof(a:any) b:string

# 接受字符串或数组类型，返回长度
func length(a:string|array) b:int

# 强制类型转换为int
func to_int(a:double) b:int

# 强制类型转换为double
func to_double(a:int) b:double

# 返回元素为[a,a+1,...b)的数组;如果b没有指定则返回元素为[1,2,...a)的数组
func range(a:int,b:int): ret:array
```