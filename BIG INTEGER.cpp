#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class Integer{
  private:
    string s;
    char sign;
  public:
    Integer(){};
    Integer(const string &st){
        s=st;
        if(st[0]=='-')
            sign='0';
        else
            sign='1';
    } 
    void print(){cout<<s<<endl;}
    Integer operator+(Integer &val);
    Integer operator-(Integer &val);
    Integer operator*(Integer &val);
    Integer operator/(Integer &val);
    Integer operator%(Integer &val); 
    bool operator==(Integer &val);
    bool operator!=(Integer &val);
    bool operator<(Integer &val);
    bool operator>(Integer &val);
    bool operator>=(Integer &val);
    bool operator<=(Integer &val);
    Integer& operator+=(Integer &val);
    Integer& operator-=(Integer &val);
    Integer& operator*=(Integer &val);
    Integer& operator/=(Integer &val);
    Integer& operator%=(Integer &val);
    string mulply(vector<int> v,char c){
        string res;
        int len=v.size(),a=int(c)-48,rem=0;
        for(int i=len-1;i>=0;i--){
            char c=char ((v[i]*a+rem)%10)  +  '0' ;
            res.push_back(  c   );
            rem=(v[i]*a+rem)/10;
        }
        res.push_back(char(rem)+'0');
        reverse(res.begin(),res.end());
        return res;
    }
    void trun(string &str){
        reverse(str.begin(),str.end());
        while(str[(str.size()-1)]=='0')
            str.pop_back();
        reverse(str.begin(),str.end());
    }
    int maxim(string s1,string s2){
        equilen(s1,s2);
        int len=s1.size();
        for(int i=0;i<len;i++){
            if(s1[i]==s2[i])
                continue;
            else if(s1[i]>s2[i])
                return 0;
            else
                return 1;
        }
        return 2;
    }
    void equilen(string &s1,string&s2){
    int l1=s1.size();
    int l2=s2.size();
    string rev;
    if(l1>l2){
        reverse(s2.begin(),s2.end());
        rev=s2;
        for(int i=1;i<=l1-l2;i++){
            rev.push_back('0');
        }
        reverse(rev.begin(),rev.end());
        s2=rev;
    } 
    if(l1<l2){
        reverse(s1.begin(),s1.end());
        rev=s1;
        for(int i=1;i<=l2-l1;i++){
            rev.push_back('0');
        }
        reverse(rev.begin(),rev.end());
        s1=rev;
    } 
    }
};
Integer& Integer::operator+=(Integer &val){
    *this=*this+val;
    return *this;
}
Integer& Integer::operator-=(Integer &val){
    *this=*this-val;
    return *this;
}
Integer& Integer::operator*=(Integer &val){
    *this=*this*val;
    return *this;
}
Integer& Integer::operator/=(Integer &val){
    *this=*this/val;
    return *this;
}
Integer& Integer::operator%=(Integer &val){
    *this=*this%val;
    return *this;
}
bool Integer ::operator>=(Integer &val){
    if(*this==val || *this>val)
        return true;
    else
        return false;
}
bool Integer ::operator<=(Integer &val){
    if(*this==val || *this<val)
        return true;
    else
        return false;
}
bool Integer::operator>(Integer &val){
    if(sign=='1'&& val.sign=='0')
        return true;
    else if(sign=='0'&& val.sign=='1')
        return false;
    else if(sign=='0'&& val.sign=='0'){
        s[0]='0';
        val.s[0]='0';
        int wh=maxim(s,val.s);
        if(wh==2)
            return false;
        else if(wh==0)
            return false;
        else if(wh==1)
            return true;
    }
    else if(sign=='1'&&val.sign=='1'){
        int wh=maxim(s,val.s);
        if(wh==2)
            return false;
        else if(wh==1)
            return false;
        else if(wh==0)
            return true;
    }
    return true;
}
bool Integer::operator<(Integer &val){
    if(sign=='1'&& val.sign=='0')
        return false;
    else if(sign=='0'&& val.sign=='1')
        return true;
    else if(sign=='0'&& val.sign=='0'){
        s[0]='0';
        val.s[0]='0';
        int wh=maxim(s,val.s);
        if(wh==2)
            return false;
        else if(wh==0)
            return true;
        else if(wh==1)
            return false;
    }
    else if(sign=='1'&&val.sign=='1'){
        int wh=maxim(s,val.s);
        if(wh==2)
            return false;
        else if(wh==1)
            return true;
        else if(wh==0)
            return false;
    }
    return true;
}
bool Integer:: operator==(Integer &val){
    if(sign!=val.sign){
        return false;
    }
    else if(sign=='1'&&val.sign=='1'){
        int wh=maxim(s,val.s);
        if(wh==2){
            return true;
        }
        else{
            return false;
        }
    }
    else if(sign=='0'&&val.sign=='0'){
        s[0]='0';
        val.s[0]='0';
        int wh=maxim(s,val.s);
        if(wh==2){
            return true;
        }
        else{
            return false;
        }
        
    }
    return true;
}
bool Integer:: operator!=(Integer &val){
    if(sign!=val.sign){
        return true;
    }
    else if(sign=='1'&&val.sign=='1'){
        int wh=maxim(s,val.s);
        if(wh==2){
            return false;
        }
        else{
            return true;
        }
    }
    else if(sign=='0'&&val.sign=='0'){
        s[0]='0';
        val.s[0]='0';
        int wh=maxim(s,val.s);
        if(wh==2){
            return false;
        }
        else{
            return true;
        }
        
    }
    return true;
}
Integer Integer:: operator+(Integer &val){
    
    if(sign=='1'&& val.sign=='1'){
        equilen(s,val.s);
        int rem=0;
        string ans;
        int i;   
        int l2=val.s.size();
        for(i =l2-1;i>=0;i--){
            int res= ((int)(s[i]-'0')+((int)(val.s[i])-'0'))+rem;
            char n=((char)res%10)+'0';
            ans.push_back(n);
            rem=res/10;
    }
        ans.push_back(char(rem)+'0');
        reverse(ans.begin(),ans.end());
        trun(ans);
        Integer final_val(ans);
        return final_val;
    }
    
    
    
    else if(sign=='0'&&val.sign=='0'){
        s[0]='0';
        val.s[0]='0';
        equilen(s,val.s);
        int rem=0;
        string ans;
        int i;   
        int l2=val.s.size();
        for(i =l2-1;i>=0;i--){
            int res= ((int)(s[i]-'0')+((int)(val.s[i])-'0'))+rem;
            char n=((char)res%10)+'0';
            ans.push_back(n);
            rem=res/10;
    }
        ans.push_back(char(rem)+'0');
        reverse(ans.begin(),ans.end());
        trun(ans);
        ans.insert(0,"-");
        Integer final_val(ans);
        return final_val;
    }
    else{
        string s1,s2;
        if(sign=='0'){
            s1=s;
            s2=val.s;
        }
        else if(val.sign=='0'){
            s1=val.s;
            s2=s;
        }
        
        s1[0]='0';
        equilen(s1,s2);
        int wh=maxim(s1,s2);
        if(wh==2){
            Integer obj("0");
            return obj;
        }
        char final_sign;
        if (wh==0)
            final_sign='-';
        if(wh==1){
            final_sign='+';
            string temp=s1;
            s1=s2;
            s2=temp;
        }
        string ans;
        for(int i=s1.size()-1;i>=0;i--){
            int a=int(s1[i])-48;
            int b=int(s2[i])-48;
            if(s1[i]==s2[i])
                ans.push_back('0');
            else if(a>b)
                ans.push_back(char(a-b)+'0');
            else{
                ans.push_back(char(10+a-b)+'0');
                int j=i;
                j--;
                while(s1[j]=='0'){
                    s1[j]='9';
                    j--;
                }
                a=int(s1[j])-48;
                a--;
                s1[j]=char(a)+'0';
            }
        }
        reverse(ans.begin(),ans.end());
        trun(ans);
        if(ans[ans.size()-1]=='0')
            ans.pop_back();
        if(final_sign=='-'){
            reverse(ans.begin(),ans.end());
            ans.push_back('-');
            reverse(ans.begin(),ans.end());
        }
        Integer final_obj(ans);
        return final_obj;
        }
    return val;
}
Integer Integer:: operator-(Integer &val){
    
    if(sign=='1'&&val.sign=='0'){
        val.sign='1';
        val.s[0]='0';
        Integer res= *this + val;
        return res;
    }
    if(sign=='1'&&val.sign=='1'){
        val.sign='0';
        val.s.insert(0,"-");
        Integer res= *this + val;
        return res;
    }
    if(sign=='0'&&val.sign=='0'){
        val.sign='1';
        val.s[0]='0';
        Integer res= val+ *this;
        return res;
        }
    if(sign=='0'&& val.sign=='1'){
        val.sign='0';
        val.s.insert(0,"-");
        Integer res= *this+ val;
        return res;
    }
    return val;    
}
Integer Integer:: operator*(Integer &val){
    char final_sign;
    if(sign=='0'&&val.sign=='0')
        final_sign='+';
    else if(sign=='1'&&val.sign=='1')
        final_sign='+';
    else if(sign=='1'&&val.sign=='0')
        final_sign='-';
    else if(sign=='0'&&val.sign=='1')
        final_sign='-';
    if(sign=='0'){
        sign='1';
        s[0]='0';
    }
    if(val.sign=='0'){
        val.sign='1';
        val.s[0]='0';
    }
    equilen(s, val.s);
    vector<int> v;
    int len=s.size();
    for(int i=0;i<len;i++){
        v.push_back(int(s[i])-48);
    }
    string sum="0";
    Integer i2(sum);
    int j;
    for(int i=len-1,j=0;i>=0;i--,j++){
        string part=mulply(v, val.s[i]);
        for(int k=1;k<=j;k++)
            part.push_back('0');
        
        Integer i1(part);
        i2=i1+i2;
    }
    if(final_sign=='-'){
        i2.s.insert(0,"-");
    }
    return i2;
}
Integer Integer:: operator/(Integer &val){
   char qfs;
    char rfs;
    if(sign=='1'&&val.sign=='1'){
        qfs='1';
        rfs='1';
    }
    else if(sign=='0'&&val.sign=='1'){
        qfs='0';
        rfs='0';
    }
    else if(sign=='1'&&val.sign=='0'){
        qfs='0';
        rfs='1';
    }
    else if(sign=='0'&&val.sign=='0'){
        qfs='1';
        rfs='0';
    }
    
    if(sign=='0'){
        sign='1';
        s[0]='0';
    }
    if(val.sign=='0'){
        val.sign='1';
        val.s[0]='0';
    }
    trun(s);
    trun(val.s);
    string &s2=val.s,quo,rem,str;
    int temp=maxim(s,s2);
    if(temp==1){
        quo.push_back('0');
        rem=s;
        if(qfs=='0')
            quo.insert(0,"-");
        Integer resobj("0");
        return resobj;
    }
    else{
        int len=s.size();
        int l=s2.size();
        for(int i=0;i<l;i++){
            str.push_back(s[i]);
        }
        int curr=l;
        while(1){
          //  cout<<"struck in 1 loop"<<endl;
            int wh=maxim(s2,str);
            int var=0;
            while(wh==0){
                if(curr<len){
                    str.push_back(s[curr]);
                    curr++;
                    if(var==1){
                        quo.push_back('0');
                    }
                    wh=maxim(s2,str);
                    var=1;
                }
                else{
                    if(var==1)
                        quo.push_back('0');
                    if(qfs=='0')
                        quo.insert(0,"-");
                    trun(quo);
                    Integer resobj(quo);
                    return resobj;   
                }
            }
           // cout<<str<<endl;
            Integer i1(s2);
            Integer i2(str);
            int i;
            for(i=1;i<10;i++){
                Integer i3(to_string(i));
                Integer i4=i1*i3;
                int check=maxim(i2.s,i4.s);
                if(check==1)
                    break;
                }
            i--;
            quo.push_back(char(i)+'0');
            Integer i3(to_string(i));
            Integer i4=i1*i3;
            //cout<<i4.s<<endl;
            i2=i2-i4;
            str=i2.s;
            //cout<<i2.s<<endl<<i4.s<<endl<<str<<endl<<endl<<endl<<endl<<endl;
        }
        
    } 
    return val;
}
Integer Integer:: operator%(Integer &val){
   char qfs;
    char rfs;
    if(sign=='1'&&val.sign=='1'){
        qfs='1';
        rfs='1';
    }
    else if(sign=='0'&&val.sign=='1'){
        qfs='0';
        rfs='0';
    }
    else if(sign=='1'&&val.sign=='0'){
        qfs='0';
        rfs='1';
    }
    else if(sign=='0'&&val.sign=='0'){
        qfs='1';
        rfs='0';
    }
    
    if(sign=='0'){
        sign='1';
        s[0]='0';
    }
    if(val.sign=='0'){
        val.sign='1';
        val.s[0]='0';
    }
    trun(s);
    trun(val.s);
    string &s2=val.s,quo,rem,str;
    int temp=maxim(s,s2);
    if(temp==1){
        quo.push_back('0');
        rem=s;
        if(rfs=='0')
            rem.insert(0,"-");
        Integer resobj(rem);
        return resobj;
    }
    else{
        int len=s.size();
        int l=s2.size();
        for(int i=0;i<l;i++){
            str.push_back(s[i]);
        }
        int curr=l;
        while(1){
            int wh=maxim(s2,str);
            int var=0;
            while(wh==0){
                if(curr<len){
                    str.push_back(s[curr]);
                    curr++;
                    if(var==1){
                        quo.push_back('0');
                    }
                    wh=maxim(s2,str);
                    var=1;
                }
                else{
                    if(var==1)
                        quo.push_back('0');
                    if(str=="0"){
                            Integer obj(str);
                            return obj;
                    }
                    if(rfs=='0')
                        str.insert(0,"-");
                    Integer resobj(str);
                    return resobj;   
                }
            }
            Integer i1(s2);
            Integer i2(str);
            int i;
            for(i=1;i<10;i++){
                Integer i3(to_string(i));
                Integer i4=i1*i3;
                int check=maxim(i2.s,i4.s);
                if(check==1)
                    break;
                }
            i--;
            quo.push_back(char(i)+'0');
            Integer i3(to_string(i));
            Integer i4=i1*i3;
            i2=i2-i4;
            str=i2.s;
        }
        
    } 
    return val;
}

int main() {

    while(1){
        string inp;
        cin>>inp;
        if(inp=="+"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            Integer i3=i1+i2;
            i3.print();
        }
        else if(inp=="-"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            Integer i3=i1-i2;
            i3.print();
        }
        else if(inp=="*"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            Integer i3=i1*i2;
            i3.print();
        }
        else if(inp=="/"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            Integer i3=i1/i2;
            i3.print();
        }
        else if(inp=="%"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            Integer i3=i1%i2;
            i3.print();
        }
        else if(inp=="=="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            bool ch=(i1==i2);
            if(!ch)
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
            
        }
        else if(inp=="!="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            bool ch=(i1!=i2);
            if(!ch)
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
            
        }
        else if(inp=="<"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            bool ch=(i1<i2);
            if(!ch)
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
            
        }
        else if(inp=="<="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            bool ch=(i1<=i2);
            if(!ch)
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
            
        }
        else if(inp==">"){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            bool ch=(i1>i2);
            if(!ch)
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
            
        }
        else if(inp==">="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            bool ch=(i1>=i2);
            if(!ch)
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
            
        }
        else if(inp=="+="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            i1+=i2;
            i1.print();
        }
        else if(inp=="+="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            i1+=i2;
            i1.print();
        }
        else if(inp=="-="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            i1-=i2;
            i1.print();
        } 
        else if(inp=="*="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            i1*=i2;
            i1.print();
        } 
        else if(inp=="/="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            i1/=i2;
            i1.print();
        } 
        else if(inp=="%="){
            string s1,s2;
            cin>>s1>>s2;
            Integer i1(s1),i2(s2);
            i1%=i2;
            i1.print();
        } 
        else if(inp=="end"){
            break;
        }
        
    }
    
    return 0;
}