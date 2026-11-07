        void MakeDeck(char deckType){
            if(deckType == 'd'){
                for(int full = 0; full < 52; ++full){
                    if(full < 4){
                        stdCard[0] = suits[0];
                        stdCard[1] = faces[full];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 3 && full < 13){
                        stdCard[0] = suits[0];
                        stdCard[1] = values[full - 4];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 12 && full < 17 ){
                        stdCard[0] = suits[1];
                        stdCard[1] = faces[full - 13];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 16 && full < 26){
                        stdCard[0] = suits[1];
                        stdCard[1] = values[full - 17];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 25 && full < 30){
                        stdCard[0] = suits[2];
                        stdCard[1] = faces[full - 26];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 29 && full < 39){
                        stdCard[0] = suits[2];
                        stdCard[1] = values[full - 30];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 38 && full < 43){
                        stdCard[0] = suits[3];
                        stdCard[1] = faces[full - 39];
                        stdDeck[full] = stdCard;
                        cout << stdDeck[full] << endl;
                    }else if(full > 42 && full < 52){
                        stdCard[0] = suits[3];
                        stdCard[1] = values[full - 43];
                        stdDeck[full] =  stdCard;
                        cout << stdDeck[full] << endl;
                    }else{
                        cout << "fail" << endl;
                    }
                }
            }else if(deckType == 'p'){
                cout << "Pinocle" << endl;
            }else if(deckType == 's'){
                cout << "Spades" << endl;
            }else{
                cout << "Choice not available" << endl;
            }
