#include <iostream>

using namespace std;

int calc(string, int);

int main()
{
    //"list" variable used to detect number of the word of the dictionary
    int N, list=0;
    cin >> N; cin.ignore();

    //Initialize the string variable used to store the input
    string dict[N];
    string letter;
    for (int i = 0; i < N; i++)
    {
        string W;
        getline(cin, W);
        dict[i]=W;
        list++;
    }
    string LETTERS;
    getline(cin, LETTERS);

    unsigned int i=0, word=0, all=0;
    int j=0, total=0, count=0, total_temp=0, duplicate=0;

    /*This loop find the all the word that can be form from dictionary after
      that, calculate the score and select the word with highest score*/
    for(j=0; j<list; j++)
    {
        i=0, all=0, word=0;
        letter=LETTERS;

        /*Check for the word in dictionary with available letter to determine
          if the word can be form or not*/
        for(all=0; all<dict[j].length(); all++)
        {
            duplicate=0;
            for(i=0; i<LETTERS.length(); i++)
            {
                if(dict[j].at(all)==letter.at(i))
                {
                    if(duplicate==0)
                    {
                        word++;
                        duplicate=1;
                        letter.at(i)=' ';
                    }
                }
            }
        }

        //If the word can be form, calculate the score
        if(word==dict[j].length())
        {
            /*Call the calc() function to calculate the score and assign the
              return value to total_temp*/
            total_temp=calc(dict[j], dict[j].length());

            /*If total is smaller that total_temp, assign total with the value
              of total_temp and set the count to the new position value*/
            if(total<total_temp)
            {
                total=total_temp;
                count=j;
            }
        }
    }

    cout << dict[count]<< endl;
    return 0;
}

int calc(string ptr, int length)
{
    int total_temp=0, i=0;
    for(i=0; i<length; i++)
    {
            if(ptr.at(i) == 'e' || ptr.at(i) == 'a' || ptr.at(i) == 'i' || ptr.at(i) == 'o' || ptr.at(i) == 'n' || ptr.at(i) == 'r' ||
            ptr.at(i) == 't' || ptr.at(i) == 'l' || ptr.at(i) == 's' || ptr.at(i) == 'u')
            {
                total_temp+=1;
            }
            if(ptr.at(i) == 'd' || ptr.at(i) == 'g')
            {
                total_temp+=2;
            }
            if(ptr.at(i) == 'b' || ptr.at(i) == 'c' || ptr.at(i) == 'm' || ptr.at(i) == 'p')
            {
                total_temp+=3;
            }
            if(ptr.at(i) == 'f' || ptr.at(i) == 'h' || ptr.at(i) == 'v' || ptr.at(i) == 'w' || ptr.at(i) == 'y')
            {
                total_temp+=4;
            }
            if(ptr.at(i) == 'k')
            {
                total_temp+=5;
            }
            if(ptr.at(i) == 'j' || ptr.at(i) == 'x')
            {
                total_temp+=8;
            }
            if(ptr.at(i) == 'q' || ptr.at(i) == 'z')
            {
                total_temp+=10;
            }
    }

    return total_temp;
}
