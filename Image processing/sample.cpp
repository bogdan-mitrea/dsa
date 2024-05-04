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