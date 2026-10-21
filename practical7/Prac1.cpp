    #include<iostream>
    using namespace std;
     int queue[100];
    int n;
    int front = -1;
    int rear = -1;
    void enqueue(int token){
        if(((rear+1)%n) == front){
            cout<<"Queue overflows\n";
            return;
        }
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }else{
            rear = (rear+1)%n;
        }
        queue[rear]=token;
    }
    void dequeue(){
        if(front == -1){
            cout<<"Queue underflows\n";
            return;
        }
        int deletedtoken = queue[front];
        cout<<"Currently deleted value is:"<<deletedtoken<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%n;
        }
    }
    void peek(){
        if(front == -1){
            cout<<"Queue is empty!";
            return;
        }
        cout<<"The current visitor to be served is:"<<queue[front]<<endl;
    }
    void display(){
        if(front == -1){
        cout<<"Queue is empty!" << endl;
        return;
    }
       int i=front;
       while(true){
        cout<<queue[i]<<" <- ";
        if(i==rear){
            break;
        }
        i= (i+1)%n;
       }
    }
    int main(){
        cout<<"Enter maximum number of visitors to the government office:";
        cin>>n;
        int choice;
        int token;
        while(true){
            cout<<endl;
            cout<<"1.Join"<<endl;
            cout<<"2.Serve token"<<endl;
            cout<<"3.Current first visitor"<<endl;
            cout<<"4.Display all visitors"<<endl;
            cout<<"5.Exit"<<endl;
            cout<<"Enter choice:";
            cin>>choice;
            if(choice == 1){
                cout<<"Enter token number of the visitor to be addded:";
                cin>>token;
                enqueue(token);
                cout<<endl;
            }
            else if(choice == 2){
                dequeue();
                cout<<endl;
                peek();
                cout<<endl;
            }
            else if(choice == 3){
                peek();
                cout<<endl;
            }
            else if(choice == 4){
                display();
                cout<<endl;
            }
            else if(choice == 5){
                cout<<"Thank you for visiting our government token office!";
                break;
            }
            else{
                cout<<"Please enter a valid choice";
            }
        }
        return 0;
    }