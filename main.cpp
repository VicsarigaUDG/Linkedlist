#include <iostream>
using namespace std;
class Vertex {
public:
  int value;
  Vertex *next;
  Vertex() { next = nullptr; }
};
class List {
public:
  List();
  void append(int value);
  void insertAt(int pos, int value);
  void insertFirst(int value);
  void removeFirst();
  void removeAt(int pos);
  void removeLast();
  void removeAtValue(int value);

  void print();

private:
  Vertex *head, *tail;
};

List::List() {
  head = nullptr;
  tail = nullptr;
}

void List::insertFirst(int value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  if (head != nullptr)
    vtx->next = head;
  else
    tail = vtx;
  head = vtx;
}

void List::append(int value) {
  Vertex *v = new Vertex();
  v->value = value;
  if (tail != nullptr) {
    tail->next = v;
  } else {
    tail = v;
    head = v;
  }
}

void List::insertAt(int pos, int value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  pos = pos - 1;

  if (pos == 0) {
    insertFirst(value);
  } else {
    Vertex *prev = head;
    for (int i = 1; i < pos && prev != nullptr; i++) {
      prev = prev->next;
    }

    if (prev == nullptr) {
      cout << "Eso no se puede D:< (Porque lo quieres tronar?)\n\n";
      return;
    }
    vtx->next = prev->next;
    prev->next = vtx;

    if (prev == tail) {
      tail = vtx;
    }
  }
}

void List::removeFirst() {
  Vertex *temp = head;
  if (head == nullptr) {
    cout << "La lista esta vacia\n";
  } else {
    head = head->next;
    delete temp;
  }
}

void List::removeAt(int pos) {
  if (head == nullptr) {
    cout << "La lista esta vacia\n\n";
  } else {
    if (pos == 0) {
      removeFirst();
    }
    if (pos < 0) {
      cout << "No se puede eliminar esa posicion\n\n";
    } else {
      Vertex *pre = head;
      for (int i = 0; i < pos - 1; i++) {

        if (pre->next == nullptr) {
          cout << "La posicion no existe\n\n";
          return;
        }
        pre = pre->next;
      }
      Vertex *del = pre->next;
      pre->next = del->next;
      delete del;
      if (pre->next == nullptr) {
        tail = pre;
      }
    }
  }
}

void List::removeAtValue(int value) {
  if (head == nullptr) {
    cout << "La lista esta vacia\n\n";
  } else if (head->value == value) {
    removeFirst();
  } else {
    Vertex *pre = head;
    while (pre->next != nullptr && pre->next->value != value) {
      pre = pre->next;
    }
    if (pre->next == nullptr) {
      cout << "El valor no existe en la lista\n\n";
    } else {
      Vertex *del = pre->next;
      pre->next = del->next;
      delete del;
      if (pre->next == nullptr) {
        tail = pre;
      }
    }
  }
}

void List::removeLast() {
  if (head == nullptr) {
    cout << "La lista esta vacia\n\n";
  } else if (head == tail) {
    delete head;
    head = nullptr;
    tail = nullptr;
  } else {
    Vertex *pre = head;
    while (pre->next->next != nullptr) {
      pre = pre->next;
    }
    delete pre->next;
    pre->next = nullptr;
    tail = pre;
  }
}

void List::print() {
  Vertex *v = head;
  while (v != nullptr) {
    cout << v->value << "->";
    v = v->next;
  }
}

int main() {

  List lista;
  lista.append(0);
  lista.insertFirst(5);
  lista.insertFirst(6);
  lista.insertAt(1, 9);
  lista.insertFirst(7);
  lista.append(2);
  // lista.insertAt(8, 2);
  lista.print();
  cout << "\n\n";

  // lista.removeAt(-1);
  // lista.removeLast();
  // lista.removeFirst();
  // lista.removeAtValue(-2);
  lista.print();
}