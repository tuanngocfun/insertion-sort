#include  <stdio.h>
#include  <string.h>

char *strInput();
char *substrInput();
char *replaceInput();
void CheckStr(char str[], char substr[], char output[], char replace[]);
//void ReplaceStr(char str[], char output[], char substr[], char replace[], int *start, int *flag);

int main() {
    char *str, *substr, *replace;
    char output[256];
    /* (start) is for if(str[i] != substr[j]), this condition satisfied then start is
     * counting till the end of replace[] string */
    /* (j) is for if(substr[j] == '\0') i.e, run till the end of substr[] string then
     * break loop */
    /* (flag) is for if(str[i] == substr[j]) i.e, this is the mark pivot point to check that
     * there is a suitable string means that exists a same character of substr[] with str[]*/

    str = strInput();
    substr = substrInput();
    replace = replaceInput();

    CheckStr(str, substr, output, replace);
    return 0;
 }

char *strInput()
{
    static char str[256];
    int length;
    printf("Please input your sentence/string: ");
    do{
        fgets(str,255,stdin);
        str[strlen(str) - 1] = '\0';

        length = 0;
        while(str[length] != '\0') length++;

        if(length <= 255) break;
        else printf("Please enter again: ");
    }while(1);
    return str;
}

char *substrInput()
{
    static char substr[128];
    int length;
    printf("Enter the string to be removed:\n");
    do{
        fgets(substr,127,stdin);
        substr[strlen(substr) - 1] = '\0';

        length = 0;
        while(substr[length] != '\0') length++;

        if(length <= 127) break;
        else printf("Please try enter again: ");
    }while(1);
    return substr;
}

char *replaceInput()
{
    static char replace[128];
    int length;
    printf("Enter the string to replace:\n");
    do{
        fgets(replace,127,stdin);
        replace[strlen(replace) - 1] = '\0';

        length = 0;
        while(replace[length] != '\0') length++;

        if(length <= 127) break;
        else printf("Please try again: ");
    }while(1);
    return replace;
}

// Check whether the substring to be replaced
void CheckStr(char str[], char substr[], char output[], char replace[])
{
    int flag = 0, i = 0, j = 0, start = 0;
    while(str[i] != '\0'){
        if(str[i] == substr[j]){
            if(!flag) start = i;
            j++;
            if(substr[j] == '\0') break;
            flag = 1;
        }
        else{
            flag = start = j = 0;
        }
        i++;
    }
    if(substr[j] == '\0' && flag)
    {
        for(i = 0; i < start; i++) output[i] = str[i];
        //replace substring with another string
        for(j = 0; j < strlen(replace); j++)
        {
            output[i] = replace[j];
            i++;
        }
        // copy remaining portion of the input string "str"
        for(j = start + strlen(substr); j < strlen(str); j++)
        {
            output[i] = str[j];
            i++;
        }
        // print the final string
        output[i] = '\0';
        printf("Output: %s\n", output);
    }
    else
        printf("%s is not a substring of %s\n", substr, str);
    /* This way is not appropriate for compiler to understand what you are really 
     * doing, since you change the substr[] then pass to function and also change 
     * it again -> it will forget the result you change at first(the former one)*/
    //ReplaceStr(str, output, substr, replace, &start, &flag);
}
/* insertion sort  */
#include <stdio.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		// for descending order arr[j] < key 
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j; // j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
