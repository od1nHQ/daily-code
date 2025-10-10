#include <stdio.h>

int main(void) {
    double x, y; // Coordinates of the point

    // Prompting the user to enter the point coordinates
    printf("Enter x: ");
    scanf("%lf", &x);  // Using the standard scanf function
    printf("Enter y: ");
    scanf("%lf", &y);

    // Display the entered coordinates
    printf("x = %6.3lf; y = %6.3lf\n", x, y);

    // Checking the first condition (where y <= -x, y >= x, and x >= -1)
    if (y <= -x && y >= x && x >= -1) {
        printf("Point is inside the region (popav)\n");
        return 0;  // Exit the program if the point satisfies the first condition
    }

    // Checking the second condition (where y <= x and x <= 1)
    if (y <= x && y >= -x && x <= 1) {  
        printf("Point is inside the region (popav)\n");
        return 0;  // Exit the program if the point satisfies the second condition
    }

    // If the point does not meet any condition
    printf("Point is outside the region (no popav)\n");

    return 0;
}
