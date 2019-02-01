#include "map.hh"

constexpr double SOLAR_MASS = 1.9884e30;
constexpr double MIN_MASS = 1e13;
constexpr double MAX_MASS = 1e17;
constexpr double DRAND_MAX = static_cast<double>(RAND_MAX);

Map::Map(Vector2D<int> dim, int n) : dim(dim) {
    int width = dim.x();
    int height = dim.y();
    for (auto i = 0; i < n; i++) {
        double m = static_cast<double>(qrand());
        double mass = (MAX_MASS - MIN_MASS) * m / DRAND_MAX + MIN_MASS;

        double x = static_cast<double>(qrand() % width);
        double y = static_cast<double>(qrand() % height);
        Vector2D<double> pos = Vector2D<double>(x, y);

        double vx = static_cast<double>(qrand() % 3 - 1);
        double vy = static_cast<double>(qrand() % 3 - 1);
        Vector2D<double> vel = Vector2D<double>(vx, vy);
        pMap.push_back(Body(pos, vel, mass));
    }
}

QVector<Vector2D<int>> Map::getPositions() const {
    QVector<Vector2D<int>> points(this->pMap.size());
    for (auto body : this->pMap) {
        Vector2D<int> p = body.getPos();
        points.append(p);
    }
    return points;
}

void Map::compute() {
    computeForces();
    computeVelocities();
    computePositions();
}

void Map::computeForces() {
    for (auto i = 0; i < this->pMap.size(); i++) {
        this->pMap[i].resetForce();
        for (auto j = 0; j < this->pMap.size(); j++) {
            if (i != j /*&& this->pMap[i].inMap(dim)*/) {
                this->pMap[i].computeForce(this->pMap[j]);
                this->pMap[i].checkCollision(this->pMap[j]);
            }
        }
    }
}

void Map::computeVelocities() {
    for (auto &body : this->pMap) {
        body.computeVelocity();
    }
}

void Map::computePositions() {
    for (auto &body : this->pMap) {
        body.computePosition();
    }
}