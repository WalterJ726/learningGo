#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    float x, y;
    Point(float x, float y) : x(x), y(y) {}
};

class Polygon {
public:
    std::vector<Point> points;

    void addPoint(float x, float y) {
        points.emplace_back(x, y);
    }

    // 这里可以添加更多的 Polygon 类方法，比如绘制多边形等
};

struct Edge {
    float yMax, xWithYMin, slopeInverse;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.xWithYMin < e2.xWithYMin;
}

void scanLineFill(Polygon& poly) {
    // 这里只处理四边形，但可以扩展到更多边形
    if (poly.points.size() != 4) {
        std::cerr << "Polygon is not a quadrilateral." << std::endl;
        return;
    }

    // 找到最小和最大的 y 坐标
    float minY = poly.points[0].y, maxY = poly.points[0].y;
    for (const auto& p : poly.points) {
        minY = std::min(minY, p.y);
        maxY = std::max(maxY, p.y);
    }

    // 创建边表
    std::vector<Edge> edges;
    for (size_t i = 0; i < poly.points.size(); i++) {
        Point p1 = poly.points[i];
        Point p2 = poly.points[(i + 1) % poly.points.size()]; // 循环到第一个点

        if (p1.y == p2.y) continue; // 忽略水平线

        Edge e;
        e.yMax = std::max(p1.y, p2.y);
        e.xWithYMin = (p1.y < p2.y) ? p1.x : p2.x;
        e.slopeInverse = (p2.x - p1.x) / (p2.y - p1.y);
        edges.push_back(e);
    }

    // 对边进行排序
    std::sort(edges.begin(), edges.end(), compareEdges);

    // 使用扫描线算法填充
    for (float y = minY; y <= maxY; y++) {
        std::vector<float> xIntersections;
        for (const auto& e : edges) {
            if (y < e.yMax && y >= e.yMax - 1) { // 检查 y 是否在边界范围内
                xIntersections.push_back(e.xWithYMin + (y - (e.yMax - 1)) * e.slopeInverse);
            }
        }

        std::sort(xIntersections.begin(), xIntersections.end());

        // 假设 xIntersections 成对出现
        for (size_t i = 0; i < xIntersections.size(); i += 2) {
            // 这里可以根据需要调整步长
            for (float x = xIntersections[i]; x < xIntersections[i + 1]; x += 1.0f) {
                poly.addPoint(x, y); // 添加填充点
            }
        }
    }
}

int main() {
    Polygon myPoly;
    myPoly.addPoint(1, 1);
    myPoly.addPoint(4, 1);
    myPoly.addPoint(4, 4);
    myPoly.addPoint(1, 4);

    scanLineFill(myPoly);

    // 打印填充的点
    for (const auto& p : myPoly.points) {
        std::cout << "Point: (" << p.x << ", " << p.y << ")" << std::endl;
    }

    return 0;
}
