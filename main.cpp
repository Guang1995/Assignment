#include <iostream>
#include <iomanip>
using namespace std;

const int TABLE_SIZE=104;
const int COURSES=1, ROOMS=2;

class table
{
protected:
  int width=18, wCount=0, space, count, turn=0;
public:
  //This function print the dash to form the table
  void lines()
  {
    for(int i=0;i<TABLE_SIZE;i++)
    {
      cout<<"-";
    }
    cout<<"\n";
  }

  // This function print the space
  void spacing()
  {
    for(count=0;count<space;count++)
    {
      cout<<" ";
    }
  }

  // This function calculate the space needed to align table properly
  void align()
  {
    if(wCount==0)
    {
      space=width;
      spacing();
    }
    else if((width-wCount)%2!=0 && turn ==0)
    {
        space=((width-wCount)/2)+((wCount/2)/3);
        while(space+wCount+(width-wCount)/2!=width)
        {
          space--;
        }
        turn=1;
        spacing();
    }
    else
    {
      space=(width-wCount)/2;
      turn=0;
      spacing();
    }
  }

  //Virtual function to the row and column derieve class
  virtual void draw()=0;
};

// The courses contain the course data for SOC sem 2 year 1 courses
class courses
{
protected:
  // Courses data that store in 2D array for reference
  int course_value[10][5]={{-1, 6, 7, 3, -1}, //8:00
                          {-1, 6, 7, 3, -1}, //9:00
                          { 5, 4, 1, 1,  4}, //10:00
                          { 7, 4, 1, 1,  4}, //11:00
                          {-1,-1,-1,-1, -1}, //12:00
                          { 5, 0, 6, 2, -1}, //13:00
                          { 5, 0, 6, 2, -1}, //14:00
                          { 3,-1, 0,-1, -1}, //15:00
                          { 3,-1,-1,-1,  2}, //16:00
                          {-1,-1,-1,-1,  2}}; //17:00

  // Room data that store in 2D array for reference
  int room_value[10][5]{{-1, 2, 5, 4, -1}, //8:00
                        {-1, 2, 5, 4, -1}, //9:00
                        { 5, 0, 5, 5,  4}, //10:00
                        { 1, 0, 5, 5,  4}, //11:00
                        {-1,-1,-1,-1, -1}, //12:00
                        { 5, 4, 4, 1, -1}, //13:00
                        { 5, 4, 4, 1, -1}, //14:00
                        { 1,-1, 2,-1, -1}, //15:00
                        { 1,-1,-1,-1,  3}, //16:00
                        {-1,-1,-1,-1,  3}}; //17:00

  // Courses data in character string as reference for the course_value and room_value
  string course_code[8]={"CSS3122", "CSS3133", "CSS3223", "CSS3313", "CSS3353", "CSN3442", "CSS3533", "CSS3542"};
  string course_name[8]={"Data Structure", "Object Oriented", "Calculus", "Multimedia", "Database Develop", "Internetworking", "Operating System", "UNIX-link Oses"};
  string course_name2[8]={"and Algorithm", "Programming", "  ", "Technology", "and Application", "Technology", "  ", "and Software Tool"};
  string course_room[6]={"R223", "R922", "R923", "R921", "Computer Lab 3", "Computer Lab 4"};
};

class row: public table, public courses
{
private:
  int nRow, v;
  // The time used to print out for every new row of the time table
  string row_time[10]={"8:00", "9:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00", "16:00", "17:00"};
public:
  // Draw the every day courses
  void draw()
  {
    for (nRow=0;nRow<10;nRow++)
    {
      //Set width and print the time in first column of each row
      cout<<"|";
      cout<<setw(6)<<row_time[nRow];
      cout<<" |";

      // Print the course code
      showCourse(COURSES, course_code, nRow);

      // Print the course name
      showCourse(COURSES, course_name, nRow);

      // Print the course name
      showCourse(COURSES, course_name2, nRow);

      // Print the room number
      showCourse(ROOMS, course_room, nRow);
      lines();
    }
  }

  void showCourse(int select, string data[8], int r)
  {
    //Check for the array and print the appropriate course details into table
    for(int c=0; c<5; c++)
    {
      switch (select)
      {
        case 1:
          v=course_value[nRow][c];
          break;
        case 2:
          v=room_value[nRow][c];
          break;
      }
      if (v>=0)
      {
          wCount=data[v].length();
          align();
          cout<<data[v];
          align();
      }
      else
      {
        align();
      }
      cout<<"|";
      wCount=0;
    }

    if(select==1)
      cout<<'\n'<<"|"<<setw(8)<<" |";
    else
      cout<<'\n';
  }
};

class column: public table
{
private:
  string column_day[5]= {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
public:
  // Draw the first row and align it by call align() function
  void draw()
  {
    cout<<"|       |";
    for (int i=0;i<5;i++)
    {
      wCount=column_day[i].length();
      align();
      cout<<column_day[i];
      align();
      cout<<"|";
    }
    cout<<'\n';
    //Draw table line layout after after complete first row
    lines();
    wCount=0;
  }
};

int main(void)
{
  table *c= new column;
  table *r= new row;

  r->lines(); // Draw the table lines layout
  c->draw(); // Draw the column of the first row of table
  r->draw(); // Draw the rest of the row of timetable

  cout<<"\n"<<"Press ENTER to exit";
  getchar();
  return 0;
}
