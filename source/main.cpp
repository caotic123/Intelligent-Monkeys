#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <limits>

#define S 10  // Don't change

// Graphics
#define square_space_x 40
#define square_space_y 20

#include "interface.h"

enum b { t_ = 0, a_ = 1, c_ = 2, _n = 3 };

float ran_() {
  float x;
  int n = 10;
  x = (float)(((rand() % (10 + 1 - 0) + 0))) / 10;
  return x;
}

// Mini-blibiotecas para auxiliar a codificação de tipos estaticos
template <typename T>
char *to_char(T i) {
  std::stringstream buffer;
  char *x = (char *)malloc(sizeof(char) * 100);
  buffer << (int)i;
  return (char *)buffer.str().c_str();
}

bool getInt_Input(int &x) {
  char buffer[100];
  std::cin >> buffer;
  x = atoi(buffer);
  return atoi(buffer) ? true : false;
}

class m_ {
 public:
  void init_agent() {
    m = (double **)malloc(sizeof(double *) * S - 1);
    for (int i = 0; i <= (S - 1); i++) {
      m[i] = (double *)malloc(sizeof(double) * 3);
      for (int x = 0; x <= 2; x++) {
        m[i][x] = ran_();
      }
    }
  }

  int add___x(int sx, b p_) {
    //	char* type = (char*)malloc(sizeof(char)*100);

    m[sx][(int)p_] += 0.1;
    // type = (char*)(p_==t_ ? "Tigre" : p_==a_ ? "Aguia" : p_==c_ ? "Cobra" :
    // "ERROR");
    // printf("Um macaquinho %d ouviu perigo de %s e ficou com valor %f\n",
    // ____id, type, m[__[0]][(int)p_]);
    return sx;
  }

  int x_get(b p_) {
    int i = 0;
    float x_ = 0;
    for (int p = 0; p <= 9; p++) {
      if (m[p][(int)p_] > x_) {
        x_ = m[p][(int)p_];
        i = p;
      }
    }
    return i;
  }

  pos getp_P() { return pos_; }

  float get_y(int n, int y) { return m[n][y]; }

  void setPos(pos x) { memcpy(&pos_, &x, sizeof(x)); }

  int ____id;

 private:
  double **m;
  pos pos_;
};

typedef struct {
  pos pos_;
  m_ *a_s;
  int p;
  b b_;
  int _;
} floor_;

class floor__ {
 public:
  void ___(int LEN_x___, int LEN_y___) {
    f = (floor_ **)malloc(sizeof(floor_ *) * LEN_x___);
    for (int i = 0; i <= (LEN_x___ - 1); i++) {
      f[i] = (floor_ *)malloc(sizeof(floor_) * LEN_y___);
    }

    __pos(LEN_x___, LEN_y___);
  }

  template <typename T>
  void __insert(T m, pos pos_) {
    memcpy(&f[pos_.x][pos_.y].b_, &m, sizeof(m));
  }

  template <typename T>
  void apon___(T &e, pos pos_) {
    f[pos_.x][pos_.y].a_s = &e;
    f[pos_.x][pos_.y]._ = f[pos_.x][pos_.y]._ + 1;
  }

  m_ *m_get___m(pos pos_) { return f[pos_.x][pos_.y].a_s; }

  b b_get___b(pos pos_) { return f[pos_.x][pos_.y].b_; }

  int getM_s(pos pos_) { return f[pos_.x][pos_.y]._; }

  void remove___m(pos pos_) {
    f[pos_.x][pos_.y].a_s = NULL;
    f[pos_.x][pos_.y]._ = f[pos_.x][pos_.y]._ - 1;
  }

  void delete____b(pos pos_) { f[pos_.x][pos_.y].b_ = _n; }

  int __;

 private:
  void __pos(int LEN_x_, int LEN_y_) {
    for (int x = 0; x <= (LEN_x_ - 1); x++) {
      for (int y = 0; y <= (LEN_y_ - 1); y++) {
        f[x][y].pos_.x = x + 1;
        f[x][y].pos_.y = y + 1;
        f[x][y]._ = 0;
        f[x][y].b_ = _n;
      }
    }
  }

  floor_ **f;
};

class AI {
 public:
  void init___p(int a___, int agents_, int ra_, int rb_, int predator_____,
                bool graphics) {
    LEN_x = a___;
    LEN_y = a___;
    area_s = ra_;
    area_view = rb_;
    agents = agents_;
    predator = predator_____;
    init__floor();
    screen = graphics;
    int x, y, p;
    pos pos_;
    if (screen) {
      ___screen->init_(LEN_x, LEN_y);
    }

    e = (int *)malloc(sizeof(int) * 9);
    for (int e_ = 0; e_ <= 9; e_++) {
      e[e_] = 0;
    }
    m___ = (m_ *)malloc(sizeof(m_) * agents);
    for (int i = 0; i <= (agents - 1); i++) {
      x = rand() % ((LEN_x - 1) + 1 - 0) + 0;
      y = rand() % ((LEN_y - 1) + 1 - 0) + 0;
      pos_.x = x;
      pos_.y = y;
      m___[i].init_agent();
      m___[i].setPos(pos_);
      m___[i].____id = i;

      if (f_x->getM_s(pos_) > 0) {
        i = i - 1;
      } else {
        f_x->apon___(m___[i], pos_);
        if (screen == true) {
          ___screen->__image((b)3, pos_);
        }
      }
    }

    for (int __ = 0; __ <= (predator - 1); __++) {
      x = rand() % ((LEN_x - 1) + 1 - 0) + 0;
      y = rand() % ((LEN_y - 1) + 1 - 0) + 0;
      p = rand() % (2 + 1 - 0) + 0;
      pos_.x = x;
      pos_.y = y;
      if (check____f(pos_.x, pos_.y) || f_x->getM_s(pos_) > 0) {
        __ = __ - 1;
      } else {
        f_x->__insert((p == 0) ? t_ : (p == 1) ? a_ : c_, pos_);
        if (screen == true) {
          ___screen->__image((p == 0) ? t_ : (p == 1) ? a_ : c_, pos_);
        }
      }
    }
  }

  void interact___() {
    pos pos_;
    int i = 0;
    for (int x = 0; x <= (LEN_x - 1); x++) {
      for (int y = 0; y <= (LEN_y - 1); y++) {
        pos_.x = x;
        pos_.y = y;
        if (f_x->getM_s(pos_) > 0) {
          i = i + 1;
          s__p_As(f_x->m_get___m(pos_), pos_);
        }
      }
    }

    if (screen) {
      _statistics((char *)NULL, false);
      ___screen->wait_and_continue();
    }
    ____realloc();
  }

  void ____realloc() {
    int x = 0, y = 0, p = 0;
    pos pos_;
    pos pos__b;

    if (screen) {
      ___screen->clean_m();
    }

    for (int x = 0; x <= (LEN_x - 1); x++) {
      for (int y = 0; y <= (LEN_y - 1); y++) {
        pos__b.x = x;
        pos__b.y = y;
        f_x->delete____b(pos__b);
      }
    }

    for (int i = 0; i <= (agents - 1); i++) {
      x = rand() % ((LEN_x - 1) + 1 - 0) + 0;
      y = rand() % ((LEN_y - 1) + 1 - 0) + 0;
      pos_.x = x;
      pos_.y = y;
      if (f_x->getM_s(pos_) > 0 || check____f(pos_.x, pos_.y)) {
        i = i - 1;
      } else {
        f_x->remove___m(m___[i].getp_P());
        f_x->apon___(m___[i], pos_);
        f_x->m_get___m(pos_)->setPos(pos_);
        if (screen == true) {
          ___screen->__image((b)3, pos_);
        }
      }
    }

    for (int __ = 0; __ <= (predator - 1); __++) {
      x = rand() % ((LEN_x - 1) + 1 - 0) + 0;
      y = rand() % ((LEN_y - 1) + 1 - 0) + 0;
      p = rand() % (2 + 1 - 0) + 0;
      pos_.x = x;
      pos_.y = y;
      if (check____f(pos_.x, pos_.y) || f_x->getM_s(pos_) > 0) {
        __ = __ - 1;
      } else {
        f_x->__insert((p == 0) ? t_ : (p == 1) ? a_ : c_, pos_);
        if (screen) {
          ___screen->__image((p == 0) ? t_ : (p == 1) ? a_ : c_, pos_);
        }
      }
    }
  }

  bool check____f(int x, int y) {
    pos pos_;
    pos_.x = x;
    pos_.y = y;
    if (f_x->b_get___b(pos_) != _n) {
      return true;
    }
    return false;
  }

  void alert____(m_ *_m, b _, int x_, int y_) {
    pos pos_;
    int m[2] = {area_s, area_s};
    int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
    int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);

    for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
      for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
        if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
          pos_.x = x;
          pos_.y = y;
          if (f_x->getM_s(pos_) > 0 &&
              _m->____id != f_x->m_get___m(pos_)->____id) {
            e[f_x->m_get___m(pos_)->add___x(_m->x_get(_), _)] += 1;
          } else if (!check____f(x, y) && f_x->getM_s(pos_) < 1) {
            if (screen) {
              ___screen->___print__floor(false, pos_);
            }
          }
        }
      }
    }
  }

  void s__p_As(m_ *m__, pos pos_) {
    int x_ = pos_.x;
    int y_ = pos_.y;
    pos b__;
    pos pos___;

    int m[2] = {area_view, area_view};

    int x__ = ((m[0] % 2) == 0) ? (m[0] / 2) - 1 : (m[0] / 2);
    int y__ = ((m[1] % 2) == 0) ? (m[1] / 2) - 1 : (m[1] / 2);

    for (int x = x_ - (m[0] / 2); x <= x_ + x__; x++) {
      for (int y = y_ - (m[1] / 2); y <= y_ + y__; y++) {
        if (x < LEN_x && y < LEN_y && x >= 0 && y >= 0) {
          pos___.x = x;
          pos___.y = y;
          if (check____f(x, y)) {
            b__.x = x;
            b__.y = y;
            alert____(m__, f_x->b_get___b(b__), m__->getp_P().x,
                      m__->getp_P().y);
          } else if (f_x->getM_s(pos___) < 1) {
            if (screen) {
              ___screen->___print__floor(true, pos___);
            }
          }
        }
      }
    }
  }

  void init__floor() {
    f_x = (floor__ *)malloc(sizeof(floor__) * 2);
    f_x->___(LEN_x, LEN_y);
    f_x->__ = 12;
  }

  void set___graphics_(interface_ *x) { ___screen = x; }

  template <typename T>
  void _statistics(T buf, bool t) {
    char x[1000] = "Dados :\n";
    char buffer[100];
    char int_[1000];
    int s;
    int a = 7;
    std::string c;
    bool screen__ = (t == false ? true : false);

    if (screen__) {
      goto msg;
    }

    for (int i = 0; i <= 9; i++) {
      s = sprintf(buffer, "was used %d %d times\n", i, e[i]);
      a = a + s;
      strncat(x, buffer, a);
    }

    a = 0;
  msg:
    for (int i = 0; i <= (agents > 10 ? 10 : agents - 1); i++) {
      if (screen__) {
        sprintf(buffer, "%d", i);
        c = (std::string) "Monkey " + buffer + (std::string) "={tigre = " +
            std::string(to_char(m___[i].x_get(t_))) +
            (std::string) ", aguia = " +
            std::string(to_char(m___[i].x_get(a_))) +
            (std::string) ", cobra = " +
            std::string(to_char(m___[i].x_get(c_))) + "}";
        ___screen->___print(c);
      } else {
        s = sprintf(buffer, "Monkey %d = {tigre = %d aguia = %d cobra = %d}\n",
                    i, m___[i].x_get(t_), m___[i].x_get(a_), m___[i].x_get(c_));
        a = a + s;
        strncat(x, buffer, a);
      }
    }

    if (!screen__) {
      strcpy(buf, x);
    }
  }

 private:
  floor__ *f_x;
  m_ *m___;
  int agents;
  int predator;
  int *e;
  bool screen;
  interface_ *___screen;
  int LEN_x;
  int LEN_y;
  int area_s;
  int area_view;
};

int main(int argc, char **argv) {
  char cons_[1000] = "";
  srand(time(NULL));
  int x = 100;
  int i = 0;
  std::string __, conf;
  int a___ = 0, agents__ = 0, predator____ = 0, rb____ = 16, ra____ = 10,
      it____ = 0;
  bool graph;
  interface_ *screen;
  AI *___AI;

  printf("                            AI - Intelligent Agents\n");
  std::cout << "This project of IA and principally intelligent agents has the "
               "purpose of\nto study the factors, standards, math calcs, "
               "behavior and logic in imperative language of programming."
            << std::endl;

  printf("What configuration you want? \"normal\" or \"higher\"\n");
  std::cin >> conf;
  if (conf == "higher" or conf == "HIGHER") {
    printf("Set area of precision of monkey vision!(only intenger number)\n");
    while (!getInt_Input(rb____)) {
      printf("Please digit one new valid number (intenger) \n");
    }
    printf("Set area of precision of monkey alert!(only intenger number)\n");
    while (!getInt_Input(ra____)) {
      printf("Please digit one new valid number (intenger) \n");
    }
  }

  printf(
      "Please define the area of your agents will be to insired (only one "
      "intenger number)");
  while (!getInt_Input(a___)) {
    printf("Please digit one new valid number (intenger) \n");
  }
  printf(
      "Please define the number of agents will be to insired its strongly "
      "recommend one number in between (1 and 10)\nCase number its higher of "
      "10 the mini-display don't show all monkeys only of\n firsts ten (only "
      "one intenger number)");

  while (!getInt_Input(agents__)) {
    printf("Please digit one new valid number (intenger) \n");
  }

  printf(
      "Please define the number of predators will be to insired its strongly "
      "recommend one number in between (1 and 10) (only one intenger number)");

  while (!getInt_Input(predator____)) {
    printf("Please digit one new valid number (intenger) \n");
  }

  printf("Please define the number of iterations\n");

  while (!getInt_Input(it____)) {
    printf("Please digit one new valid number (intenger) \n");
  }

  printf("Active mode graphical?\n");
  std::cin >> __;
  if (__ == "true" || __ == "TRUE" || __ == "YES" || __ == "yes") {
    graph = true;
    printf("Mode graphical actived\n");
  } else {
    graph = false;
    printf("Mode graphical OFF\n");
  }

  screen = new interface_;
  ___AI = new AI;
  if (graph) {
    ___AI->set___graphics_(screen);
  }
  ___AI->init___p(a___, agents__, ra____, rb____, predator____, graph);
  for (i = 0; i < it____;) {
    ___AI->interact___();
    i++;
  }
  ___AI->_statistics(cons_, true);
  printf("%s\n", cons_);

  if (graph) {
    screen->close___();
  }

  printf("Enter whatever key of to continue\n");
  delete ___AI;
  system("pause");

  return 0;
}
