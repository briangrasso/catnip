else if((Program.filename == "blogin.html") && (Program.rVarValue[0] != "on")){
            Program.passArgs = "blogin ";
            for(int q = 0; q < 3; q++){
                Program.passArgs = Program.passArgs + Program.rVarValue[q] + " ";
            }
            Program.passArgs = Program.passArgs + "a" + " a" + " a" + " a" + " a" + " a" + " a";
            Program.passArgs = Program.passArgs + " =";
            Console.WriteLine("Program.passArgs IN BLOGIN: " + Program.passArgs);
                                    static async Task<int> RunLogind2(string fileName2, string args22){
                                        var M2process = new Process{
                                            StartInfo = new ProcessStartInfo{
                                            FileName = fileName2,
                                            Arguments = args22,
                                            RedirectStandardOutput = true,
                                            RedirectStandardError = true,
                                            UseShellExecute = false,
                                            CreateNoWindow = true
                                        }
                                    };
                                    try{
                                        M2process.Start();
                                    }catch(Exception anyEx2){
                                        Console.WriteLine($"The Start exception: {anyEx2}");
                                    }
                                    await Task.Run(() => M2process.WaitForExit());
                                    return M2process.ExitCode;
                                    }
                                    try{
                                        int catchRes2 = await RunLogind2("D:\\casino\\stablecoin\\bank\\casinoD\\logind\\logind.exe", Program.passArgs);
                                        Console.WriteLine($"Exit Code: {catchRes2}");
                                        if(catchRes2 == 8){
                                            Program.path = "webroot\\wwwroot\\bank\\members\\" + Program.rVarValue[0] + "\\" + Program.rVarValue[0] + ".html";
                                        }else if(catchRes2 == 10){
                                            Program.path = "webroot/wwwroot/bank/relogin.html";
                                        }            
                                    }catch(Exception someEx2){
                                        Console.WriteLine($"Error: {someEx2.Message}");
                                    } 