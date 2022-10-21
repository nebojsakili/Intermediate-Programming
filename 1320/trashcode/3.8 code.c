int main(int argc, char **argv)
{
    int lotto_nums[ALL_DAYS][6];
    int status = 0, counter = 0;
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    char **days_ptr = days;
}

char line[100];
char *token;

while(!feof(fp))
{
    fgets(line, 100, fp);
    token=strtok(line, ",");

    while(token)
    {
        val[j][i]=atoi(token);
        token=strtok(NULL, ",\n"); //keep going from the same place in the same string
    }
    i = 0;
    j++;
}