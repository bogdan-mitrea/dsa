#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void merge(vector<int>& v, int p, int q, int r)
{
    vector<int> temp;
    int i, j;
    i = p;
    j = q + 1;
    while(i <= q && j <= r)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= q)
    {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= r)
    {
        temp.push_back(v[j]);
        j++;
    }
    for (int i = p; i <= r; i++)
        v[i] = temp[i - p];
}

void mergeSort(vector<int>& v, int begin, int end)
{
    if(begin >= end) return;
    int mid = (begin + end) / 2;
    mergeSort(v, begin, mid);
    mergeSort(v, mid + 1, end);
    merge(v, begin, mid, end);
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
    ofstream g(file_out);
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
    int** image = new int *[height];
    for(int i = 0; i < height; i++)
        image[i] = new int[width];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
        {
            f >> image[i][j];
        }
    int pixel;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            vector<int> for_sort;
            for(int x = i - dim / 2; x <= i + dim / 2; x++)
                for(int y = j - dim / 2; y <= j + dim / 2; y++)
                {
                    if(x < 0 && y >= 0 && y <= width - 1) pixel = image[0][y]; //sus
                    if(x >= 0 && x <= height - 1 && y < 0) pixel = image[x][0]; //stanga
                    if(x < 0 && y < 0) pixel = image[0][0]; //stanga sus
                    if(x >= 0 && x <= height - 1 && y >= 0 && y <= width) pixel = image[x][y]; //centru
                    if(x >= height && y >= width) pixel = image[height - 1][width - 1]; //dreapta jos
                    if(x >= height && y >= 0 && y <= width - 1) pixel = image[height - 1][y]; // jos
                    if(x >= 0 && x <= height - 1 && y >= width) pixel = image[x][width - 1]; //dreapta
                    if(x >= height && y < 0) pixel = image[height - 1][0]; //stanga jos
                    if(x < 0 && y >= width) pixel = image[0][width - 1]; //dreapta sus
                    for_sort.push_back(pixel);
                }
            if(sort_mode == "bubble")
            {
                for(int i1 = 0; i1 < for_sort.size() - 1; i1++)
                    for(int j1 = i1 + 1; j1 < for_sort.size(); j1++)
                    {
                        if(for_sort[i1] > for_sort[j1]) swap(for_sort[i1], for_sort[j1]);
                    }
            }
            if(sort_mode == "merge")
            {
                mergeSort(for_sort, 0, (int) for_sort.size() - 1);
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