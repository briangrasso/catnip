    public async Task ParseFunc(string newQuery){
        Program.pBlankCount = 0;
        for(ushort order = 2; order < newQuery.Length; ++order){
            if(newQuery[order] == '\n' | newQuery[order] == '\r' | newQuery[order] == '\0'){
                    Program.pBlanksArr[Program.pBlankCount] = order;
                Program.pBlankCount++;
            }else if(newQuery[order] == '\\'){
                Program.bsLoc[Program.bsCount] = order;
                ++Program.bsCount;
                for(int bs = 0; bs < Program.bsCount; ++bs){
                Console.WriteLine("bsCount: " + (bs + 1) + "\t" + "bsLoc: " + (Program.bsLoc[bs] - 2));
                }
            }else if(newQuery[order] == '/'){
                Program.fsLoc[Program.fsCount] = order;
                ++Program.fsCount;
                for(int fs = 0; fs < Program.fsCount; ++fs){
                Console.WriteLine("fsCount: " + (fs + 1) + "\t" + "fsLoc: " + (Program.fsLoc[fs] - 2));
                }
            }else if(newQuery[order] == '.'){
                Program.perLoc[Program.perCount] = order;
                ++Program.perCount;
                for(int per = 0; per < Program.perCount; ++per){
                Console.WriteLine("perCount: " + (per + 1) + "\t" + "perLoc: " + (Program.perLoc[per] - 2));
                }
            }else if(newQuery[order] == '?'){
                Program.qmLoc = order;
                Console.WriteLine("qmLoc: " + (Program.qmLoc - 2));
            }else if(newQuery[order] == '\n'){
                Program.nlLoc[Program.nlCount] = order;
                ++Program.nlCount;
            }else if(newQuery[order] == '\r'){
                Program.crLoc[Program.crCount] = order;
                ++Program.crCount;
            }else if(newQuery[order] == '='){
                Program.eqLoc[Program.eqCount] = order;
                ++Program.eqCount;
                for(int eq = 0; eq < Program.eqCount; ++eq){
                Console.WriteLine("eqCount: " + (eq + 1) + "\t" + "eqLoc: " + (Program.eqLoc[eq] - 2));
                }
            }else if(newQuery[order] == '&'){
                Program.ampLoc[Program.ampCount] = order;
                ++Program.ampCount;
                for(int amp = 0; amp < Program.ampCount; ++amp){
                Console.WriteLine("ampCount: " + (amp + 1) + "\t" + "ampLoc: " + (Program.ampLoc[amp] - 2));
                }
            }else if((newQuery[order] == '*') && (newQuery[order - 1] == '*') && (newQuery[order - 2] == '*')){
                for(ushort parX = ++order; parX < newQuery.Length; ++parX){
                    Program.parsedCom = Program.parsedCom + newQuery[parX];
                }
                Console.WriteLine("parsedCom: " + Program.parsedCom);
                if(Program.parsedCom == ""){
                    AdminFunc("exit");
                }else{
                    AdminFunc(Program.parsedCom);
                }
            }else
                continue;
        }
    }