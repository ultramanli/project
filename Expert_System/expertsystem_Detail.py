import pymysql
car=[]#车辆
ff=[]#全部特征集
rules=[]#规则集
rear=[]#后件集
feature=[]#选择的特征
drop=[]#drop=[dropin,dropin,dropin] dropin=[当前被替换的,[后件集]]

db = pymysql.connect("localhost","root","root","test",charset='utf8' )  
cursor = db.cursor()# 使用cursor()方法获取操作游标
#########读取车辆############################
sql = "SELECT * FROM car"
cursor.execute(sql)
results = cursor.fetchall()
for row in results:
     car.append(row[1])
#########读取全部特征集############################
sql = "SELECT * FROM feature"
cursor.execute(sql)
results = cursor.fetchall()
for row in results:
     ff.append(row[1]) 
#########读取规则集前件############################
sql = "SELECT * FROM rules"
cursor.execute(sql)
results = cursor.fetchall()
for row in results:
    rulein=row[0].split()
    rules.append(rulein)
#########读取规则集后件############################
sql = "SELECT * FROM rules"
cursor.execute(sql)
results = cursor.fetchall()
for row in results:
    rear.append(row[1])
    
    
    
db.close()
#########读取菜单############################
menu=[]
for line in open("menu.txt","r"):
    menu.append(line.strip('\n'))
    
    
    
    
##########函数定义###############################
def menu1(): 
    for i in menu:
      if(i=='#'):
        print('\n')
      else:
        print(i,end=' ')
    return 0

def tui():
    while(1):#没得出结果之前的大循环
        whilec=True#当特征集改变时从头遍历规则集
        ruleid=0#规则id 用来匹配对应后件
        for rule in rules:
            print(feature,' ',ruleid,rule)#!!!!!
            infeature=True
            #########当前规则前件是否都在特征集里，不都在则下一规则####################
            for i in rule:
                if i not in feature:
                    infeature=False
                    break
            if infeature==False:
                print("不全在")#!!!!!
                ruleid=ruleid+1
               # input("test")#!!!!!
                continue
            ################################## 
            print("在",ruleid)#!!!!!
            #input("test")#!!!!!
            #if(rear[ruleid] not in feature):  #若当前规则后件不在特征集里，则加入，前件删除后进drop
                # feature.append(rear[ruleid])#后件入特征
                # featureid=feature.index(rule[0])#后件入特征，插入待删除前件之前
            feature.insert(0,rear[ruleid])
            dropin=[rear[ruleid],[]]#drop=[dropin,dropin,dropin] dropin=[当前被替换的,[后件集]]
                 #########冲突集构建###############################
            idin=ruleid
            
            for i in range(idin+1,len(rules)):#从当前规则前件之后开始寻找冲突
                if(rules[i]==rule):
                         dropin[1].append(rear[i])
            dropin[1].append(rules[ruleid])#原特征入栈底    
            dropin[1].reverse()#倒置后件表为后面解决冲突出栈使用
                 
            drop.append(dropin)
                 
                 ###########################################
                 ###########################################
            for i in rule:#特征扔掉前件
              feature.remove(i)#remove第一个匹配项
            ruleid=ruleid+1#准备查看下一规则
            print(drop,'构建了冲突集')#!!!!!
            print(feature,'现特征集')#!!!!!
            whilec=False#特征集有变化，从第一个规则重新遍历
            break
        if(whilec==False):
            continue
        featurenow=list(set(feature))#重复项归一并变为列表   
        if(len(featurenow)==1):#判断是否唯一 若唯一判断是否为结果，否则判断drop是否为0，若不为0则替换或回溯替换，否则失败
                  for i in car:#判断是否为结果
                    if(featurenow[0]==i):
                     
                     return i
        ########为1不return或不为1则解决冲突
        while(len(drop)!=0):#若冲突集不为0
         
                   dropin=drop[-1]#不为0则取最近一个发生冲突的元素
                   if(len(dropin[1])>1):#替换   dropin[1]还有未替换的其他后件 1个是前件
                    #if(dropin[1][0] not in feature):#可替换后件不在特征集中
                       changed=dropin[0]#待被替换的值
                       dropin[0]=dropin[1].pop()#出栈，作为下一次被替换的后件
                       feature[feature.index(changed)]=dropin[0]#后件之一出栈替换特征集中的1个上次后件
                       print(feature,'进行替换')#!!!!!
                       print(drop,'drop集')#!!!!!
                       break#进入下一次所有规则遍历
                   else:#回溯+替换    dropin[1]里只有前件，无可替换后件，则回溯并替换上一个dropin
                       changed=dropin[0]#待被回溯的值
                       dropin[0]=dropin[1].pop()#前件出栈
                       feature.extend(dropin[0])#前件元素回到特征集 
                       feature.remove(changed)#删掉一个被回溯的后件
                       drop.pop()#删除空dropin
                       print(feature,'进行回溯')#!!!!!
                       print(drop,'drop集')#!!!!!
                       continue#上一个dropin替换 
                   
                    
                 
        if(len(drop)==0):return 0#冲突集为空 当前特征集没有可替换项目 失败
        ######冲突解决完毕，成功或失败则return，否则进入下一遍遍历全部规则

################主函数######################################################
import os     
while(1):
    os.system('cls')
    menu1()
    print('\n') 
    a=input("请输入特征(每次输入1个特征，回车键录入，q结束输入):")
    print('\n')
    if(a=='q'):break
    
    feature.append(a)
show=feature.copy()
if(len(feature)<4):
    waring='---输入特征较少，结果可能有偏差，仅供参考---'
else:
    waring='----结果仅供参考----'
    
result=tui()
if(result!=0):
     db = pymysql.connect("localhost","root","root","test",charset='utf8' )  
     cursor = db.cursor()# 使用cursor()方法获取操作游标
#########读取车辆信息############################
     sql = "SELECT * FROM result WHERE car = '%s'"%(result)
     cursor.execute(sql)
     results = cursor.fetchall()
     for row in results:
        message=row[2]
     sql = "SELECT * FROM rules WHERE rear = '%s'"%(result)
     cursor.execute(sql)
     results = cursor.fetchall()
     qian=[]#前件
     hou=[]#后件
     cid=[]#规则号
     for row in results:
        qian.append(row[0])
        hou.append(row[1])
        cid.append(row[2])
     print('输入的特征为：',show,'\n')
     print(waring)           
     print('这个车可能是:',result)
     print(message,'\n')
     c=input("是否查询规则？（Y/N）：")
     if(c=='Y' or c=='y'):
          for i in range(0,len(qian)):
            print('使用了规则'+str(cid[i])+':  '+qian[i]+'--->'+hou[i])
     input('谢谢使用！按任意键退出系统')
else:
    print('输入的特征为：',show,'\n')
    print(waring)
    print('没有这种车')   
    input('谢谢使用！按任意键退出系统')         
            
