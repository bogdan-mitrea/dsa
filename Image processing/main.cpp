#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int pixel(int*** img, int i, int j)
{
    if(i < 0 && j >= 0) return *img[0][j];
    if(i >= 0 && j < 0) return *img[i][0];
    if(i < 0) return *img[0][0];
    return *img[i][j];
}

int main()
{
    string sort_mode;
    cin >> sort_mode;
    int dim;
    cin >> dim;
    string file_in, file_out;
    cin >> file_in >> file_out;
    ifstream f(file_in);
    f.open(file_in);
    ofstream g(file_out);
    g.open(file_out);
    string P2;
    f >> P2;
    int width, height;
    f >> width;
    while(width == 0)
    {
        getline(f, P2);
        f >> width;
    }
    f >> height;
    int white;
    f >> white;
    while(white == 0)
    {
        getline(f, P2);
        f >> white;
    }
    g << "P2" << endl << width << " " << height << endl << white << endl;
    int** image = new int *[width];
    for(int i = 0; i < width; i++)
        image[i] = new int[height];
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
        {
            f >> image[i][j];
        }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            vector<int> for_sort;
            for(int x = i - dim / 2; x <= i + dim / 2; x++)
                for(int y = j - dim / 2; y <= j + dim / 2; y++)
                {
                    for_sort.push_back(pixel(&image, x, y));
                }
            if(sort_mode == "bubble")
            {
                for(int i1 = 0; i1 < for_sort.size() - 1; i1++)
                    for(int j1 = i + 1; j1 < for_sort.size(); j1++)
                    {
                        if(for_sort[i1] > for_sort[j1]) swap(for_sort[i1], for_sort[j1]);
                    }
            }
            if(sort_mode == "merge")
            {

            }
            g << for_sort[dim * dim / 2] << " ";
            for_sort.clear();
        }
        g << endl;
    }
    f.close();
    g.close();
    return 0;
}