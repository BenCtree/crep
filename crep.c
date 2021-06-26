// crep.c
// ben crabtree, 2021

# include <stdio.h>
# include <string.h>

# define LINE_LEN 100

// Searches a line of text for a given string
// Returns 1 if found and 0 if not found
int search_for_string(char* line, char* string, int len_string)
{
    int num_matches = 0;
    char search_ch;
    int line_len = strlen(line);
    for (int i = 0; i < line_len; i++)
    {
        search_ch = string[num_matches];
        char line_ch = line[i];
        if (line_ch == search_ch)
        {
            num_matches++;
            if (num_matches == len_string) return 1;
        }
        else num_matches = 0;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Please enter a text file name. \n");
        return 1;
    }

    if (argc >=2 && argc < 3)
    {
        printf("Please enter a string to crep for. \n");
        return 1;
    }

    char* string = argv[1];
    char* filename = argv[2];
    int len_string = strlen(string);
    
    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file. \n");
        return 1;
    }

    char line[LINE_LEN];
    int line_num = 1;
    int string_found = 0;
    printf("Searching for string... \n");
    while ( fgets(line, LINE_LEN, fp) != NULL )
    {
        if (search_for_string(line, string, len_string) == 1)
        {
            string_found = 1;
            printf("%d\t", line_num);
            puts(line);
        }
        line_num++;
    }
    if (string_found == 0) printf("String not found. \n");

    fclose(fp);

    return 0;

}