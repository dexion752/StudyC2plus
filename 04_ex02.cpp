#include <iostream>

using namespace std;

class Point
{
public:
    Point (int pos_x, int pos_y);
    virtual ~Point ();

private:
    /* data */
    int x;
    int y;
};

class Geometry
{
public:
    Geometry (Point **point_list);
    Geometry();
    virtual ~Geometry ();

    void AddPoint(const Point &point);

    // 모든 점들 간의 거리를 출력하는 함수
    void PointDistance();

    // 모든 점들을 잇는 직선을 간의 교점의 수를 출력해주는 함수
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x, y) - ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1)과 (x2, y2)가 f(x,y)=0을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y2) * f(x2, y2) <= 0 이면 됩니다.
    void PointNumMeets();

private:
    /* data */
    Point* point_array[100];
};

void Geometry::AddPoint(const Point &point)
{
    
}

void Geometry::PointDistance()
{
    
}

void Geometry::PointNumMeets()
{
    
}
