/*
Written By Hale Walls on 12/5/23
Pre: All the information has been read from the file. 
Post: The teller has logged in using their username and password. 
Purpose: To allow tellers to log in using their account info. 
*/
void login(string tellerinfo[][2], int numTellers)
{
    string username, password, target = ""; //defining variables.
    cout << "Please enter your username: ";
    cin >> username;
    for (int i = 0; i < numTellers; i++) //searches list of tellers for the input.
    {
        if (username == tellerinfo[i][0])
            target = tellerinfo[i][1];
    }
    if (target == "") //if input isn't valid, send back to start.
    {
        cout << "That username is not in our database." << endl;
        login(tellerinfo, numTellers);
    }
    else
    {
        cout << "Please enter your password: "; //prompts for password.
        cin >> password;
        if (password == target) //checks for validity.
        {
            return;
        }
        else
        {
            cout << "That is not the correct password." << endl;
            login(tellerinfo, numTellers);
        }
    }
}
