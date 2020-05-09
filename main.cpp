#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <string>
using matrix = std::vector<std::vector<int>>;
void print_matrix(matrix vec){
    for(auto line:vec){
            std::cout<<"\t";
        for(int i:line){
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}
matrix Matrix_multiplier(matrix v1,matrix v2){
    matrix finished_matrix(5, std::vector<int>(5,0));
    for (int i = 0; i<5; i++){
        for (int j=0; j < 5; j++){
            for (int k=0; k<5;k++)
                finished_matrix[i][j]+=v1[i][k]*v2[k][j];
        }
    }
    return finished_matrix;
}
matrix Matrix_creator(){
    std::vector<std::vector<int>> v(5, std::vector<int>(5,0));
    for(auto &line:v){
        for(int &i:line){
            i=rand()%2;
        }
    }
    return v;
}
void reduce(matrix &new_matrix){
    for(auto &line:new_matrix){
        for(int &i:line){
            if(i>1){
                i=1;
            }
        }
    }
}
void process(int n){
    matrix starting_matrix=Matrix_creator();
    std::cout<<"Randomly generated zero-one matrix:\n";
    print_matrix(starting_matrix);
    std::cout<<"\n";
    matrix final_matrix=starting_matrix;
    std::cout<<"that matrix to the boolean power of "<<n<<":\n";
    for(int i=1;i<n;i++){
        final_matrix=Matrix_multiplier(starting_matrix,final_matrix);
        reduce(final_matrix);
    }
    print_matrix(final_matrix);
}
void choice(){
    int n;
    srand(time(NULL));
    std::cout<<"Please enter the boolean power of n you want your randomly generated 5X5 zero-one matrix:\n";
    if(!(std::cin>>n)||n==0||n<1){
        std::cout<<"Please enter a valid positive number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice();
    }
    else{
        process(n);
    }
}
main(){
    choice();
}
