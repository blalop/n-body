#ifndef MAP_HH
#define MAP_HH

#include "bhtree.hh"
#include "body.hh"
#include "quadrant.hh"

#include <array>
#include <boost/thread/barrier.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

class Map {
  public:
    Map(double deltatime, int iters);
    virtual ~Map();
    std::vector<Body> getBodies() const;
    Quadrant getQuadrant() const;
    virtual void compute() = 0;
    friend std::istream &operator>>(std::istream &s, std::shared_ptr<Map> map);
    friend std::ostream &operator<<(std::ostream &s,
                                    const std::shared_ptr<Map> map);

  protected:
    double deltatime;
    int iters;
    std::vector<Body> bodies;
    Quadrant quadrant;
};

class MapBrute : public Map {
  public:
    MapBrute(double deltatime, int iters);
    void compute();
};

class MapBHTree : public Map {
  public:
    MapBHTree(double deltatime, int iters);
    void compute();
};

class MapParallel : public Map {
  public:
    MapParallel(double deltatime, int iters);
    virtual ~MapParallel();
    void compute();
    void threadRoutine(int id);

  private:
    std::vector<std::thread> threads;
    static constexpr int THREADS = 4;
    boost::barrier entry, build, calculate;
    std::array<BHTree *, MapParallel::THREADS> trees;
    std::array<std::vector<Body *>, MapParallel::THREADS> qBodies;
    std::atomic_int32_t i;

    BHTree bhtree;
};

#endif // MAP_HH
