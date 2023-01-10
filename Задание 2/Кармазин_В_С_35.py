class Graph:

    # Сортировка для вывода списка смежности
    def sorting(g):
        for i in range(len(g)):
            g[i].sort()

    # Спепаратор
    def sep(self):
        print("\n-------------------------\n")

    # Первый эелемент, смежный с v
    def first(g, v):
        Graph.sep()
        if (g[v - 1] != []):
            return(g[v - 1][0])
        else:
            print("У этой вершины нет смежных элементов")
            return
        Graph.sep()

    # i-ый элемент из списка элементов, смежных с v
    def index(g, v, i):
        Graph.sep()
        if (g[v - 1][i + 1] != []):
            return(g[v - 1][i + 1])
        else:
            print('Вершины, следющей за индексом i не существует')
            return
        Graph.sep()

    # Вершина
    def vertex(g, v, i):
        Graph.sep()
        if (g[v - 1][i] != []):
            return(g[v - 1][i])
        else:
            print(f'Вершины с индексом {i}, смежной с вершиной {v} не существует')
            return
        Graph.sep()

    # Удаление узла
    def del_v(g, v):
        g.pop(v - 1)
        for i in range(len(g)):
            for j in range(len(g[i])):
                try:
                    g[i].remove(v)
                except:
                    continue
    # Удаление ребра
    def del_e(vesa, v, w):
        tmp = str(v) + str(w)
        vesa.pop(tmp)

    # Изменение веса ребра
    def edit_e(vesa, v, w, q):
        Graph.sep()
        tmp = str(v) + str(w)
        try:
            vesa.pop(tmp)
            vesa.setdefault(tmp, q)
        except:
            print("Такой дуги не существует")
        Graph.sep()

    # Добавление вершшины и вывод всех вершин
    def add_v_user(g):
        Graph.sep()
        g.append([])
        print('Все вершины:', end=' ')
        for i in range(len(g)):
            print(i + 1, end=' ')
        Graph.sep()

    def add_v(g):
        g.append([])

    # Добавление дуги и её веса
    def add_e_user(g, vesa):
        Graph.sep()
        print("Из какой вершины пойдет ребро:", end=' ')
        answer1 = int(input())
        print("В какую вершину пойдет ребро:", end=' ')
        answer2 = int(input())
        g[answer1 - 1].append(answer2)
        print("Введите вес дуги:", end=' ')
        ves = int(input())
        tmp = str(answer1) + str(answer2)
        vesa.setdefault(tmp, ves)
        print('Готово', end='')
        Graph.sep()

    def add_e(g, a1, a2, vesa, ves):
        g[a1 - 1].append(a2)
        tmp = str(a1) + str(a2)
        vesa.setdefault(tmp, ves)

    # Вывод списка смежности
    def show(g):
        Graph.sep()
        for i in range(len(g)):
            print(f'Вершина {i + 1}:', end=' ')
            print(g[i])
        Graph.sep()


graph = Graph()

# Создание списка смежности и словаря весов дуг
g = []
vesa = {}

while(True):
    print("1 - добавить вершину и показать все вершины")
    print("2 - создать ребро ")
    print("3 - указать везз ребра ")
    print("4 - показать список смежности")
    print("5 - показать словарь весов")
    print("0 - Выйти")
    ans = int(input("Выберете пункт меню "))

    if  ans == 1:
        graph.add_v_user(g)

    elif ans ==2:
        graph.add_e_user(g, vesa)

    elif ans == 4:
        graph.show(g)

    elif ans == 5:
        graph.show_vesa(vesa)

    elif ans == 6:
        v = int(input())
        graph.first(g, v)

    elif ans == 0:
        break


    graph.sorting(g)
