struct tayo{
    static const int shape_size_y = 3, shape_size_x = 3; //character size (2,2), Caution! y axis first then x axis and starts with (0,0)
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y, move_x, "##)"); //character head, (0,2) part of in size(2,2)
        mvaddstr(move_y + this->shape_size_y-2, move_x, "##)"); //character body, (1,2) part of in size(2,2)
        mvaddstr(move_y + this->shape_size_y-1, move_x, "@ @"); //character leg, (2,2) part of in size(2,2)
    }
};

struct python{
    static const char shape_size_x = 6;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y, move_x, "PYTHON");
    }
};


struct css{
    static const char shape_size_x = 3;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y, move_x, "CSS");
    }
};

struct cpp{
    static const char shape_size_y = 3;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-2, move_x, "C"); mvaddstr(move_y-1, move_x, "+"); mvaddstr(move_y, move_x, "+");
    }
};

struct html{
    static const char shape_size_y = 2, shape_size_x = 2;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y, move_x, "HT");
        mvaddstr(move_y+1, move_x, "ML");
    }
};


/*
namespace는 한 파일에 한번만 사용하는 것이 좋다!

헤더파일은 함수를 선언하는 것들을 모은 것이라고 보면 됨
namespace, struct, class 등은 헤더파일에 작성하고, cpp파일에는 함수의 기능을 작성한다!
그리고 하나의 cpp파일에는 하나의 hpp파일을 만드는 것이 좋다.
*/