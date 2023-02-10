#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000010
int tot;

struct Node
{
    int key;
    int value;
    struct Node *next;
};

struct Node *head[N];

void insert(int key, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = head[tot];
    head[tot] = newNode;
}

int find(int key)
{
    for (struct Node *current = head[tot]; current; current = current->next)
    {
        if (current->key == key)
        {
            return current->value;
        }
    }
    return -1;
}

void clear()
{
    tot++;
    memset(head + tot, 0, sizeof(struct node *));
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    clear();
    int *result = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        int index = find(target - nums[i]);
        if (index != -1 && i != index)
        {
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            break;
        }
        else
        {
            insert(nums[i], i);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int nums[] = {-10, 7, 19, 15};
    int target = 9;

    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize = 2;
    int *result = twoSum(nums, numsSize, target, &returnSize);

    printf("%d - %d", result[0], result[1]);

    return 0;
}