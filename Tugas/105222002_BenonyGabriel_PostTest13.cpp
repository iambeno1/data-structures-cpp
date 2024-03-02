#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        pNode->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

void inputData(struct TrieNode *root)
{
    char inputKey[32];

    printf("Masukkan kata, ketik 'exit' untuk berhenti:\n");

    while (1)
    {
        printf("Masukkan kata: ");
        scanf("%s", inputKey);

        if (strcmp(inputKey, "exit") == 0)
            break;

        insert(root, inputKey);
    }
}

int main()
{
    struct TrieNode *root = getNode();

    // Memasukkan data menggunakan fungsi inputData
    inputData(root);

    // Mencari berbagai kata kunci
    printf("%s --- %s\n", "the", search(root, "the") ? "Terdapat dalam trie" : "Tidak terdapat dalam trie");
    printf("%s --- %s\n", "these", search(root, "these") ? "Terdapat dalam trie" : "Tidak terdapat dalam trie");
    printf("%s --- %s\n", "their", search(root, "their") ? "Terdapat dalam trie" : "Tidak terdapat dalam trie");
    printf("%s --- %s\n", "thaw", search(root, "thaw") ? "Terdapat dalam trie" : "Tidak terdapat dalam trie");

    return 0;
}