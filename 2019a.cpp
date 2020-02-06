#include<cstdio>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

const int maxv=100010;
int a,b;
int tab[maxv];
vector<int> ans;

bool isSu(int x){
	for(int i=2;i<sqrt(x)+1;i++){
        if(x%i==0) return false;
	}
    return true;
}

int main(){
    fill(tab,tab+maxv,true);
	scanf("%d%d",&a,&b);
	for(int i=2;i<=b;i++){
        if(tab[i]==false) continue;
        if(isSu(i) && i>=a){
            tab[i]=true;
            ans.push_back(i);
        }
        for(int j=1;j*i<=b;j++) tab[j*i]=false;
	}

	bool flag=false,flag2=false;  //flag1作用是一组等差数列的开始，flag2作用是输入完一组等差数列后回车
	for(int i=1;i<ans.size();i++){
        if(flag && ans[i]-ans[i-1]==ans[i-1]-ans[i-2]){
            printf("%d ",ans[i]);
        }else{
            flag=false;
            if(flag2){
                flag2=false;
                printf("\n");
            }
        }
        if(!flag && i!=ans.size()-1 && ans[i-1]+ans[i+1]==2*ans[i]){
            flag=true;
            flag2=true;
            printf("%d %d ",ans[i-1],ans[i]);
        }
	}
	if(flag2) printf("\n");

    return 0;
}
