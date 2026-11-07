        int ShuffleD(){
          srand(time(0));
                    do{
                            holdAll[invCounter - 2] = rand() % (counter);
                            if(holdAll[invCounter - 2] == counter - 1){
                                do{
                                holdAll[invCounter - 2] = rand() % (counter);
                                }while(holdAll[invCounter - 2] == counter - 1);
                            }
                                    for(int n = 0; n < 2; n++){
                                        hold52[invCounter - 2][n] = stdDeck[holdAll[invCounter - 2]][n];
                                    }
                     printf("%d\n", holdAll[invCounter - 2]);
					try{
                     for(int w = 0; w < 2; w++){
                        printf("%c", hold52[invCounter - 2][w]);
                     }
                     }catch(string anEx){cout << anEx << endl;};
                     cout << endl;
               stdDeck.erase(stdDeck.begin() + holdAll[invCounter - 2]);                                   
                     counter--;
                     invCounter++;
                     cout << "Counter: " << counter << "\tinvCounter: " << invCounter - 2 << endl;
                    }while(counter > 1);                    
                        counter = 53;
                        invCounter = 2;
                     cout << "End Shuffle" << endl;
            return 0;
        }