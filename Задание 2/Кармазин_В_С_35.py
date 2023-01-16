# Вариант 35
# Алгоритм: Определить наличие всех циклов методом обхода в глубину на орграфе. Вывести все циклы (варианты обхода, образующие циклы). Подсчитать их общее количество.
# Способ представления графа: Список смежности

#1.	FIRST(v) - возвращает индекс первой вершины, смежной с вершиной v. Если вершина v не имеет смежных вершин, то возвращается "нулевая" вершина .
#2.	NEXT(v, i)- возвращает индекс вершины, смежной с вершиной v, следующий за индексом i. Если i — это индекс последней вершины, смежной с вершиной v, то возвращается .
#3.	VERTEX(v, i) - возвращает вершину с индексом i из множества вершин, смежных с v.
#4.	ADD_V(<имя>, <метка, mark>) - добавить УЗЕЛ
#5.	ADD_Е(v, w, c) - добавить ДУГУ (здесь c — вес, цена дуги (v,w))
#6.	DEL_V(<имя>) - удалить УЗЕЛ
#7.	DEL_Е(v, w) – удалить ДУГУ
#8.	EDIT_V(<имя>, <новое значение метки или маркировки>) - изменить метку (маркировку) УЗЛА
#9. EDIT_Е(v, w, <новый вес дуги>) - изменить вес ДУГИ




class Graph:

    # Сортировка для вывода списка смежности
    def sorting(self,g):
        self.g = g
        for i in range(len(g)):
            g[i].sort()

    # Спепаратор
    def sep(self):
        print("\n-------------------------\n")

    # Первый эелемент, смежный с v
    def first(self,g, v):
        self.g =g
        self.v =v
        Graph.sep(self)
        if (g[v - 1] != []):
            return(g[v - 1][0])
        else:
            print("У этой вершины нет смежных элементов")
            return
        Graph.sep()

    # i-ый элемент из списка элементов, смежных с v
    def index(self,g, v, i):
        self.g =g
        self.v = v
        self.i = i
        Graph.sep(self)
        if (g[v - 1][i + 1] != []):
            return(g[v - 1][i + 1])
        else:
            print('Вершины, следющей за индексом i не существует')
            return
        Graph.sep(self)

    # Вершина
    def vertex(self,g, v, i):
        self.g = g
        self.v = v
        self.i = i
        Graph.sep(self)
        if (g[v - 1][i] != []):
            return(g[v - 1][i])
        else:
            print(f'Вершины с индексом {i}, смежной с вершиной {v} не существует')
            return
        Graph.sep(self)

    # Удаление узла
    def del_v(self,g, v):
        self.g = g
        self.v = v
        g.pop(v - 1)
        for i in range(len(g)):
            for j in range(len(g[i])):
                try:
                    g[i].remove(v)
                except:
                    continue
    # Удаление ребра
    def del_e(self,vesa, v, w):
        self.vesa = vesa
        self.v= v
        self.w = w
        tmp = str(v) + str(w)
        vesa.pop(tmp)

    # Изменение веса ребра
    def edit_e(self,vesa, v, w, q):
        self.vesa = vesa
        self.v = v
        self.w = w
        self.q = q
        Graph.sep(self)
        tmp = str(v) + str(w)
        try:
            vesa.pop(tmp)
            vesa.setdefault(tmp, q)
        except:
            print("Такой дуги не существует")
        Graph.sep(self)

    # Добавление вершшины и вывод всех вершин
    def add_v_user(self,g):
        self.g = g

        Graph.sep(self)
        g.append([])
        print('Все вершины:', end=' ')
        for i in range(len(g)):
            print(i + 1, end=' ')
        Graph.sep(self)

    def add_v(self,g):
        self.g = g
        g.append([])

    # Добавление дуги и её веса
    def add_e_user(self,g, vesa):
        self.g = g
        self.vesa =vesa
        Graph.sep(self)
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
        Graph.sep(self)

    def add_e(self,g, a1, a2, vesa, ves):
        self.g= g
        self.a1= a1
        self.a2= a2
        self.vesa= vesa
        self.ves = ves
        g[a1 - 1].append(a2)
        tmp = str(a1) + str(a2)
        vesa.setdefault(tmp, ves)

    # Вывод списка смежности
    def show(self,g):
        self.g =g
        Graph.sep(self)
        for i in range(len(g)):
            print(f'Вершина {i + 1}:', end=' ')
            print(g[i])
        Graph.sep(self)

    def show_vesa(self, vesa):
        self.vesa = vesa

        for i in vesa.items():
            print(i[0], ":", i[1])

    # Обход в глубину

    def dfs(self, visited, graph, node):
        self.visited = visited
        self.graph = graph
        self.node = node

        if node not in visited:
            visited.append(node)
            for n in graph[node-1]:
                Graph.dfs(self, visited, graph, n)

    # Задание

    def dfs_task(self, visited, graph, node, count):
        self.visited = visited
        self.graph = graph
        self.node = node
        self.count = count

        if node not in visited:
            visited.append(node)
            for n in graph[node-1]:
                Graph.dfs_task(self, visited, graph, n, count)
        else:
            count += 1
            return

graph = Graph()

# Создание списка смежности и словаря весов дуг
g = []
vesa = {}
visited = []


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
        graph.dfs(visited, g, 1)

    elif ans == 7:
        print(visited)

    elif ans == 8:
        count = 0
        for i in range(len(g)):
            visited = []
            graph.dfs_task(visited, g, i+1, count)
        print(count)

    elif ans == 0:
        break


    graph.sorting(g)
