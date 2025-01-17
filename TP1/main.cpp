
Save New Duplicate & Edit Just Text Twitter
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
#include <iostream>
#include <cassert>

using std::cout;
using std::cin;


unsigned getCantidadDias(unsigned mes, unsigned anio);
bool esBisiesto(unsigned anio);

int main(){
    
    {//Pruebas
        void TestCantDias();
        void TestBisiestos();
    
        TestCantDias();
        TestBisiestos();
    
        cout << "La funcion paso las pruebas\n\n";
    }
    
    {//Aplicación
        unsigned SolicitarMes();
        unsigned SolicitarAnio();
        void ValidarMesAnio(unsigned mes, unsigned anio);

        ValidarMesAnio(
            SolicitarMes(),
            SolicitarAnio()         
        );
    }
}

unsigned SolicitarMes(){
    cout << "Ingrese un mes:\n";
    unsigned mes;
    cin >> mes;
    return mes;
}
    

unsigned SolicitarAnio(){
    cout << "Ingrese un anio:\n";
    unsigned anio;
    cin >> anio; 
    return anio;
}

void ValidarMesAnio(unsigned mes, unsigned anio){
    mes<1 or mes>12   ? cout << mes << " no es un mes valido." :   
                        anio < 1583 or anio > 3020 ?
                        cout << anio << " no es un anio valido." :
                        cout << "La cantidad de dias es: " << getCantidadDias(mes, anio);
}


void TestCantDias(){
    assert(31 == getCantidadDias(1,2020));
    assert(29 == getCantidadDias(2,2020));
    assert(28 == getCantidadDias(2,1583));
    assert(31 == getCantidadDias(3,2020));
    assert(30 == getCantidadDias(4,2020));
    assert(31 == getCantidadDias(5,2020));
    assert(30 == getCantidadDias(6,2020));
    assert(31 == getCantidadDias(7,2020));
    assert(31 == getCantidadDias(8,2020));
    assert(30 == getCantidadDias(9,2020));
    assert(31 == getCantidadDias(10,2020));
    assert(30 == getCantidadDias(11,2020));
    assert(31 == getCantidadDias(12,2020));
}

void TestBisiestos(){
    assert(esBisiesto(1600));
    assert(!esBisiesto(1700));
    assert(!esBisiesto(1800));
    assert(!esBisiesto(1900));
    assert(esBisiesto(1584));
    assert(esBisiesto(1628));
    assert(esBisiesto(1776));
    assert(esBisiesto(1888));
    assert(esBisiesto(1912));
    assert(!esBisiesto(1700));
    assert(esBisiesto(2004));
    assert(esBisiesto(2020));
    assert(!esBisiesto(2021));
    assert(esBisiesto(2044));
    assert(!esBisiesto(2094));
    assert(esBisiesto(2096));
}

bool esBisiesto(unsigned anio){
    /*  DESCRIPCION:    
        PRECONDICIONES: */
    assert(anio > 1582 and anio < 3021);
    return  (anio % 4 == 0) and (anio % 100!=0) or
            (anio % 4 == 0) and (anio % 100==0) and (anio % 400==0);
    // (divisible por 4 y no divisible por 100 => bisiesto) O (divisible por 4 y 100 y por 400 => bisiesto)
}



unsigned getCantidadDias(unsigned mes, unsigned anio){
    /*  DESCRIPCION:
        PRECONDICIONES:     */
    assert(mes < 13 and mes > 0);
    return (mes == 4 or mes == 6 or mes == 9 or mes == 11) ?
        30 :
        mes != 2 ? 
            31 :
            esBisiesto(anio) ?
                29 :
                28
    ;
}