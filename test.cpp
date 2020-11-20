#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char *FloStr1 = "1. RTC control system (7.13-8.28)";
    // string FloStr1 = "1. RTC control system (7.13-8.28) - Data structure and algorithm, Linux Fundamental & Shell Programming, HTML5/CSS, JavaScript (Ajax, Xml, node.js), Python syntax, Web Framework (Django) DBMS structure and data modeling, Database (SQL/NoSQL) 2. Big data real-time analysis (8.31-9.4) - Introduction to Statistics, Data Crawl & Scraping 1. RTC control system-Sub Project (9.7-9.11) Data analysis using Python library 2. Big data real-time analysis (9.14-10.23) - Visualization, Data preprocessing, Distributed system (Hadoop, Spark, etc.), Big Data Real-Time Analysis-Sub Project 2-1. Data Analysis Mentoring Data Analysis Mentoring 9.26/10.17 Sat/Sat 3. Comprehensive flight [on-site training] (10.27-11.9) Understanding the types and structure of drone equipment, Aviation related laws and ultra-light aircraft aviation laws, Take-off and landing and emergency procedures, Aerial operation and non-superficial operation, Comprehensive Flight-Sub Project 4. Custom drone production and control system (11.10-12.3) - Embedded system, Network for data transmission, Flight mechanics, Custom drone production and control system-Sub Project 5. Autonomous flight using artificial intelligence (12.4-1.26) - Introduction to Artificial Intelligence, machine learning, Deep learning algorithms, Image processing using OpenCV, OpenCV image data set detection learning, Self-driving car learning, Drone autonomous flight using central control system-Main Project 5-1. Artificial Intelligence Mentoring Artificial Intelligence Mentoring 12.19/1.9 Sat/Sat 6. Design Thinking Project planning through brainstorming using design thinking 10.5-10.6 7. Idea Bank vocational career training, resume + personal letter correction, consulting on how to apply for employment through company and related job analysis 10.26/11.21/11.28 Mon/Sat/Sat 8. Final Project (1.11-1.27)";

    cout << strlen(FloStr1) << endl;

    for (int i = 0; i < strlen(FloStr1); i++){
        cout << FloStr1[i] << endl ;
    }

    return 0;
}