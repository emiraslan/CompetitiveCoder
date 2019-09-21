//
//  main.cpp
//  DevCompetitive
//
//  Created by Amiraslan Bakhshili on 9/21/19.
//  Copyright © 2019 Amiraslan Bakhshili. All rights reserved.
//

#include <iostream>
#include <vector>

#define lastItemRight ( stk[stk.size()-1] + input[stk[stk.size()-1]] )
#define lastItemLeft ( stk[stk.size()-1] - input[stk[stk.size()-1]] )

#define previousItemRight ( stk[stk.size()-2] + input[stk[stk.size()-2]] )
#define previousItemLeft ( stk[stk.size()-2] - input[stk[stk.size()-2]] )

#define currentLeft ( i - input[i] )
#define currentRight ( i + input[i] )

int main(int argc, const char * argv[]) {
    
    int input[] = { 0, 0, 1, 1, 1, 2, 0, 0, 0, 2, 4, 1, 3, 2, 1, 0, 0, 1, 3, 2 };
    int countInput = sizeof(input)/sizeof(int);
    
    std::vector<int> stk;
    
    for(int i = 0; i < countInput; i++){
        if(!stk.empty() && lastItemRight >= currentRight)
            continue;
        
        if (!stk.empty() && lastItemLeft >= currentLeft)
        {
            while(
                  lastItemLeft >= currentLeft
                  ) stk.pop_back();
            
            if (stk.size() > 2 &&
               lastItemLeft < currentLeft &&
               lastItemRight < currentRight &&
               lastItemRight > currentLeft &&
                
               previousItemLeft < currentLeft &&
               previousItemRight < currentRight &&
               previousItemRight >= currentLeft
                ){
                stk.pop_back();
            }
        }
        
        stk.push_back(i);
    }
    
    for(auto &it : stk){
        std::cout << it << " ";
    }
    
    std::cout << std::endl << "The answer is: " << stk.size() << "\n";
    
    return 0;
}
