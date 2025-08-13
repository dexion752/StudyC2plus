#include <iostream>

class Date
{
public:
    void SetDate(int year, int month, int date)
    {
        year_ = year;
        month_ = month;
        day_ = date;
        LunnarCheck(year_);
    }
    void LunnarCheck(int year_)
    {
        if ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0)) {
            lunnarFlag_ = true;
        } else {
            lunnarFlag_ = false;
        }
    }
    void AddDay(int inc)
    {
        int feb;
        // 윤년, 2월 날수 처리
        if (lunnarFlag_) {
            feb = 29; 
        } else {
            feb = 28;
        }

        int sum = day_ + inc;
        // 1년 단위를 먼저 처리
        if (sum > 365) {
            // 1년 이상의 날수가 입력되는 경우, 한해를 단순히 365로 나누어 처리하면 부정확한 결과를 얻게 된다. 윤년(366일)을 제대로 반영하지 못했기 때문이다. 따라서 지금과 다른 방식으로 처리해야 한다.₩
           AddYear(sum / 365); 
           sum = sum % 365;
        }
        for (int i = month_; i <= 12; i++) {
           if (i == 2) {
               if (sum > feb) {
                   month_++;
                   sum -= feb;
               }
               if (sum < feb) {
                   day_ = sum;
                   break;
               }  
           } else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) { 
               if (sum > 31) {
                     month_++;
                     sum -= 31; 
               } else if (sum == 31) {
                   day_ = sum;
                   break;
               } 
               if (sum < 31) {
                      day_ = sum;
                      break;
               } 
           } else {
               if (sum > 30) {
                   month_++;
                   sum -= 30;
               } else if ( sum == 30) {
                   day_ = sum;
                   break;
               }
               if (sum < 30 ) {
                   day_ = sum;
                   break;
               }
           } 
        }  
    } 
    void AddMonth(int inc)
    {
        int sum = month_ + inc;
        if (sum > 12) {
            year_ += sum / 12;
            month_ = sum % 12;
        } else {
            month_ = sum;
        }
    }
    void AddYear(int inc)
    {
        year_ += inc;
        LunnarCheck(year_);
    }

    void ShowDate()
    {
        std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_ << "일 ";
        if (lunnarFlag_) {
            std::cout << "윤년입니다." << std::endl;
        } else {
            std::cout << "평년입니다." << std::endl;
        }
    }

private:
    /* data */
    int year_;
    int month_;
    int day_;
    bool lunnarFlag_;
};

int main(int argc, char *argv[])
{
    Date day;
    day.SetDate(2011, 3, 1);
    day.ShowDate();
    
    day.AddDay(30);
    day.ShowDate();

    day.AddDay(2000);
    day.ShowDate();

    day.SetDate(2012, 1, 31);
    day.AddDay(29);
    day.ShowDate();

    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();
    
    return 0;
}

