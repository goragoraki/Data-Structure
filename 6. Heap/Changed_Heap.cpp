const int MAX_HEAP = 100001;

struct node{
    int id = -1;
    int income = -1;
};
bool mx(node src, node dst){
    if(src.income == dst.income){
        if(src.id < dst.id)
            return true;
        return false;
    }else if(src.income > dst.income){
        return true;
    }else
        return false;
}
class heap{
    public:
        heap(){
            size = 0;
        }
        void hinit(){
            size = 0;
        }
        bool empty(){
            if(size == 0)
                return true;
            return false;
        }
        void push(int x, int y){
            data[++size].id = x;
            data[size].income = y;
            for (int i = size; (i / 2) != 0 && mx(data[i],data[i/2]); i/=2){
                data[i].id = data[i / 2].id;
                data[i].income = data[i / 2].income;
                data[i / 2].id = x;
                data[i / 2].income = y;
            }
        }
        void top(int& id, int& income){
            if(size == 0){
                id = -1;
                income = -1;
            }else{
                id = data[1].id;
                income = data[1].income;
            }
        }
        
        void pop(){
            if(size!=0){
                data[1].id = data[size].id;
                data[1].income = data[size--].income;
                for (int i = 1; (i * 2) <= size;){
                    if((i*2) == size || mx(data[i*2], data[i*2+1])){
                        if(mx(data[i*2],data[i])){
                            int t1 = data[i].id;
                            int t2 = data[i].income;
                            data[i].id = data[i * 2].id;
                            data[i].income = data[i * 2].income;
                            data[i * 2].id = t1;
                            data[i * 2].income = t2;
                            i = i * 2;
                        }else
                            break;
                    }else{
                        if(mx(data[i*2+1],data[i])){
                            int t1 = data[i].id;
                            int t2 = data[i].income;
                            data[i].id = data[i * 2+1].id;
                            data[i].income = data[i * 2+1].income;
                            data[i * 2+1].id = t1;
                            data[i * 2+1].income = t2;
                            i = i * 2 + 1;
                        }else
                            break;
                    }
                }
            }
        }
    private:
        node data[MAX_HEAP];
        int size;
};
heap hp;

int getTop10(int result[10]) 
{
    int mid = 0;
    int mincome = 0;
    int result2[10], idx = 0;
    while(!hp.empty() && idx!=10){
        hp.top(mid, mincome);
    
        result[idx] = mid;
        result2[idx] = mincome;
        idx++;
        hp.pop();
    }
    for (int i = 0; i < idx;i++){
        hp.push(result[i], result2[i]);
    }
    return idx; // return number of top 10 people 
}