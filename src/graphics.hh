#ifndef GRAPHICS_HH
#define GRAPHICS_HH

#include "body.hh"
#include "data/vector2d.hh"
#include "map.hh"

#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QWidget>

#include <memory>

class Graphics : public QWidget {
    Q_OBJECT

  public:
    Graphics(QWidget *parent, Vector2D<int> dim, int refresh_rate, int n);
    ~Graphics();

  protected:
    void paintEvent(QPaintEvent *);

  private:
    enum Color { black, white };
    Vector2D<int> dim;
    QImage image;
    std::unique_ptr<QTimer> timer;
    Map map;

  private slots:
    void step();
};

#endif // GRAPHICS_HH
