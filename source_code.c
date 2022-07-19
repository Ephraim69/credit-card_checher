#include "cs50.h"
#include <stdio.h>

// Determines if a Credit Card number is valid!
int main(void)
{
    int i = 0, sum = 0;
    int arr1[20];
    long num, tmp;

    // Get Card Number!
    num = get_long("Number: ");
    tmp = num;

    // Convert the number to an array of integers
    while (tmp)
    {
        arr1[i] = tmp % 10;
        tmp /= 10;
        i++;
    }
    // Declare 2 arrays that will store every other digit
    int arr2[i];
    int arr3[i];
    int k = 0, l = 0;

    // Digits to be multiplied by '2' are stored in arr[2] others in arr[3]
    for (int j = 0; j < i; j++)
    {
        if ((j + 1) % 2 == 0)
        {
            arr2[k] = arr1[j];
            k++;
        }
        if ((j % 2) == 0)
        {
            arr3[l] = arr1[j];
            l++;
        }
    }
    // Multiply each number in arr[2] by '2' and add every digit in sum
    for (int j = 0; j < k; j++)
    {
        arr2[j] = arr2[j] * 2;
        sum += (arr2[j] / 10) + (arr2[j] % 10);
    }
    // Add the value stored in 'sum' to the sum of digits in arr[3]
    for (int j = 0; j < l; j++)
    {
        sum += arr3[j];
    }
    int arr[2];
    // Check if the last digit of that sum is 0
    if (sum % 10 == 0)
    {
        // Checks for American Express cards
        if (i == 15)
        {
            for (int j = 0; j < (i - 2); j++)
            {
                num /= 10;
            }
            if (num == 34 || num == 37)
            {
                printf("AMEX\n");
                return (0);
            }
        }
        // Checks for MasterCard and VISA cards
        else if (i == 16)
        {
            for (int j = 0; j < (i - 2); j++)
            {
                num /= 10;
            }
            if (num == 51 || num == 52 || num == 53 || num == 54 || num ==55)
            {
                printf("MASTERCARD\n");
                return (0);
            }
            // Checks for VISA cards of length 4
            num /= 10;
            if (num == 4)
            {
                printf("VISA\n");
                return (0);
            }
        }
        // Checks for VISA cards of length 13
        else if (i == 13)
        {
            for (int j = 0; j < (i - 1); j++)
            {
                num /= 10;
            }
            if (num == 4)
            {
                printf("VISA\n");
                return (0);
            }
        }
        // If every other conditions are false, then the card is neither Amex, Visa or Mastercard
        printf("INVALID\n");
    }
    // Not a Valid Card
    else
    {
        printf("INVALID\n");
    }
}
