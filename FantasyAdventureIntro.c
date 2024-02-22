// Welcomes adventurers to the Ethereal Isles, checks for "he-man" user name,
// then displays a unieuq message also  looks for 'm' in the username and 
// displays a message that the user has extra perspective points.

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char player_name[MAX_LENGTH];
    char land_name[] = "Ethereal Isles"; // Fancy name for the fantasy role play land
    char npc_name[] = "Elder Osryian"; // Name for the NPC
    char welcome_message[MAX_LENGTH + 100]; // Length of welcome message may be up to 100 characters longer than player's name
    char game_title[] = "Mystic Quest"; // Game title string
    char *m_position; // Pointer to store the position of 'm' in the game title

    // Ask the player for their username
    printf("%s: Welcome to the %s! What's your adventurer name? ", npc_name, land_name);
    scanf("%s", player_name);

    // Check if the adventurer name is "he-man" and display special message if true
    if (strcmp(player_name, "he-man") == 0) {
        printf("%s: Behold! The chosen one! I sense great power within you.\n", npc_name);
    } else {
        // Concatenate strings to create the customized welcome message
        strcpy(welcome_message, npc_name);
        strcat(welcome_message, ": Greetings, ");
        strcat(welcome_message, player_name);
        strcat(welcome_message, "! Welcome to the enchanting ");
        strcat(welcome_message, land_name);
        strcat(welcome_message, ". Prepare yourself for a grand adventure!\n");

        // Display the customized welcome message
        printf("\n%s\n", welcome_message);
        printf("%s: As you step into the realm, a mystical aura surrounds you.\n", npc_name);

        // Print the welcome message in reverse
        printf("%s: \"", player_name);
        for (int i = strlen(welcome_message) - 1; i >= 0; i--) {
            printf("%c", welcome_message[i]);
        }
        printf("\"\n");

        // Find the position of 'm' in the username
        m_position = strchr(player_name, 'm');
        if (m_position != NULL) {
            printf("%s: Ah, the fabled %s, I see you have potential here is %ld extra perspective points.\n", npc_name, player_name, (m_position - player_name)+1);
        } else {
            printf("%s: You don't feel very special %s \n", npc_name, player_name);
        }
    }

    return 0;
}
