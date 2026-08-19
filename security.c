#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

// シーザー暗号（指定したシフト数だけ文字をずらす）
void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift % 26 + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift % 26 + 26) % 26 + 'A';
        }
    }
}

// XOR暗号（鍵文字列とのXOR演算による可逆暗号）
void xor_cipher(char *text, const char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    
    if (key_len == 0) return;

    for (int i = 0; i < text_len; i++) {
        text[i] = text[i] ^ key[i % key_len];
    }
}

// 入力バッファのクリア
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int choice;
    char text[MAX_LEN];
    char key[MAX_LEN];
    int shift;

    while (1) {
        printf("\n=====================================\n");
        printf("  セキュリティアルゴリズム コンソール\n");
        printf("=====================================\n");
        printf("1. シーザー暗号 (暗号化/復号)\n");
        printf("2. XOR暗号 (暗号化/復号)\n");
        printf("3. 終了\n");
        printf("選択してください (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (choice == 3) {
            printf("プログラムを終了します。\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\n--- シーザー暗号 ---\n");
                printf("文字列を入力: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0'; // 改行削除

                printf("シフト数を入力 (正: 暗号化 / 負: 復号): ");
                scanf("%d", &shift);
                clear_input_buffer();

                caesar_cipher(text, shift);
                printf("結果: %s\n", text);
                break;

            case 2:
                printf("\n--- XOR暗号 ---\n");
                printf("文字列を入力: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';

                printf("暗号鍵を入力: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';

                xor_cipher(text, key);
                printf("結果 (文字列表示): %s\n", text);
                break;

            default:
                printf("無効な選択です。\n");
                break;
        }
    }

    return 0;
}
