#include <stdio.h>

int main(int argc, char *argv[])
{
    char *names[] = {
        "Bob", "Michael F.", "MontezumaFrankEvansJuniorTheThirdlakdnf;ladkn;lakdsncladn;lasdlk;fjad;kljfaldknfl;adnl;kfadnf"
    };

    printf("The size of names is %ld\nnames[0]: %ld\nnames[1]:%ld\nnames[2]: %ld\n", sizeof(names), sizeof(names[0]), sizeof(names[1]), sizeof(*names[2]));

    int height = 5;
    int *hp = &height;

    char name[] = "mike";
    printf("\nname: %s\n", name);
    printf("name + 2: %c\n\n", *(name + 2));

    printf("Height: %d at %p\n", height, hp);

    return 1;
}
