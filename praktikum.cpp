/* Praktikum 1 Komutasi Numerik (E)
 * Kelompok 10
 * Anggota : 
 * 1. Irsyad Fikriansyah Ramadhan (5025211149)
 * 2. Immanuel Pascanov Samosir (5025211257)
 * 3. Akmal Nafis (5025211216)
 */

#include <iostream>

#include <stdlib.h>
#include <cmath>
#include <string>

#include "pbPlots.hpp"
#include "supportLib.hpp"

double f(double x, int code){
    switch (code){
    case 1:
        return pow(x, 3) - 3 * x + 1;
        break;
    case 2:
        return cos(x) - 3 * x;
        break;
    case 3:
        return pow(10, x) + 2 * x - 100;
        break;
    case 4:
        return log(x) - 1 - (1 / pow(x, 2));
        break;
    case 5:
        return exp(x) - log(x) - 20;
        break;
    case 6:
        return pow(10, x) - 1;
        break;
    case 7:
        return exp(-x) - x;
        break;
    default:
        cout << "Error! wrong code." << endl;
        exit(1);
    }
}

int main(){
    double x1, x2, x3, fx1, fx2, fx3, batasBawah, batasAtas;
    int code;

    cout << "Persamaan:" << endl;
    cout << "(1) x^3 - 3x + 1" << endl;
    cout << "(2) Cos x = 3x" << endl;
    cout << "(3) 10^x = 100 - 2x" << endl;
    cout << "(4) ln x = 1 + 1 / x^2" << endl;
    cout << "(5) e^x - ln x = 20" << endl;
    cout << "(6) 10^x - 1 " << endl;
    cout << "(7) e^(-x) - x " << endl;

    cout << endl
         << "Pilih persamaan\t: ";
    cin >> code;

    cout << "Batas Bawah\t: ";
    cin >> batasBawah;

    cout << "Batas atas\t: ";
    cin >> batasAtas;

    char bdr[] = "────────────";

    printf("┌%7s┬%12s┬%12s┬%12s┬%12s┬%12s┬%12s┐\n", "───────", bdr, bdr, bdr, bdr, bdr, bdr);
    printf("│%7s│%12s│%12s│%12s│%12s│%12s│%12s│\n", "iterasi", "x1", "x2", "x3", "f(x1)", "f(x2)", "f(x3)");
    printf("├%7s┼%12s┼%12s┼%12s┼%12s┼%12s┼%12s┤\n", "───────", bdr, bdr, bdr, bdr, bdr, bdr);

    x1 = batasBawah;
    x2 = batasAtas;
    for (int i = 0; i <= 100; i++){
        x3 = (x1 + x2) / 2;
        fx1 = f(x1, code);
        fx2 = f(x2, code);
        fx3 = f(x3, code);

        printf("│%7d│%12lf│%12lf│%12lf│%12lf│%12lf│%12lf│\n", i, x1, x2, x3, fx1, fx2, fx3);

        if (fx2 * fx3 < 0.0) // minus
            x1 = x3;
        else
            x2 = x3;

        if (fabs(fx3) < 0.001)
            break;
        else if (fabs(fx3) > 0.001 && i == 100)
            x3 = INFINITY;
    }
    printf("└%7s┴%12s┴%12s┴%12s┴%12s┴%12s┴%12s┘\n", "───────", bdr, bdr, bdr, bdr, bdr, bdr);

    cout << "Aproksimasi penyelesaian di x = " << x3 << endl;

    /* for Graph */
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    vector<double> x, y;

    for (float i = batasBawah; i < batasAtas; i += 0.1){
        x.push_back(i);
        y.push_back(f(i, code));
    }

    ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
    series -> xs = &x;
    series -> ys = &y;
    series -> linearInterpolation = true;
    series -> lineType = toVector(L"dotted");
    series -> lineThickness = 2;
    series -> color = GetGray(0.3);

    ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
    settings -> width = 800;
    settings -> height = 600;
    settings -> autoBoundaries = true;
    settings -> autoPadding = true;

    switch (code){
    case 1:
        settings -> title = toVector(L"x^3 - 3x + 1");
        break;
    case 2:
        settings -> title = toVector(L"Cos x = 3x");
        break;
    case 3:
        settings -> title = toVector(L"10^x = 100 - 2x");
        break;
    case 4:
        settings -> title = toVector(L"ln x = 1 + 1 / x^2");
        break;
    case 5:
        settings -> title = toVector(L"e^x - ln x = 20");
        break;
    case 6:
        settings -> title = toVector(L"10^x - 1");
        break;
    case 7:
        settings -> title = toVector(L"e^(-x) - x");
        break;

    default:
        break;
    }

    settings -> xLabel = toVector(L"X axis");
    settings -> yLabel = toVector(L"Y axis");
    settings -> scatterPlotSeries -> push_back(series);

    DrawScatterPlotFromSettings(imageReference, settings);

    vector<double> *pngdata = ConvertToPNG(imageReference -> image);
    WriteToFile(pngdata, "plot.jpg");
    DeleteImage(imageReference -> image);

    return 0;
}

/* how to run:
 *  g++ praktikum.cpp pbPlots.cpp supportLib.cpp
 *  ./a.out
 */
