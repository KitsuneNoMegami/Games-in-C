#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "game.h"

const char *dico[] = {"apple","table","river","stone","music","bread","jelly","cable","sugar","cloud","plant","chair","truck","mouse","light","sound","water","heart","glass","train","party","house","brush","knife","crown","fruit","money","piano","beach","movie","flute","grape","clock","earth","field","flame","grill","lemon","magic","night","ocean","paint","peach","phone","plane","queen","raven","river","salad","sheep","shirt","skate","smile","snake","space","spoon","storm","story","sword","teeth","tiger","toast","torch","track","train","valve","watch","whale","wheat","wheel","zebra","angel","apron","bacon","badge","baker","basil","beard","beast","begin","berry","bison","blade","bless","block","blues","boast","brace","brick","bride","bring","broom","brush","build","cabin","camel","canal","candy","cargo","carve","catch","chain","chalk","charm","chess","chick","chill","choir","cider","claim","clash","cliff","cloak","clown","coach","coral","crane","crash","cream","creek","crisp","cross","crown","crush","curve","dance","debut","delta","devil","diary","diner","ditch","diver","dolph","donut","drain","dream","dress","drift","drink","drone","eagle","earth","elder","elbow","ember","error","fairy","faith","false","fancy","feast","fence","fetch","fiber","field","fiend","flair","flock","flora","flute","focus","forge","fraud","fresh","frost","giant","glade","glove","gnome","grace","grape","graph","grasp","grill","grove","habit","haven","hazel","heart","hedge","hello","hinge","honor","horse","hotel","hover","human","humid","humor","hymn","image","imply","index","infer","input","irony","islet","issue","ivory","joker","judge","juice","jolly","karma","kneel","knock","label","laser","latte","layer","lemon","linen","liver","logic","lunar","lunch","lunge","magic","mania","march","match","medal","melon","merit","metal","micro","miner","minim","minor","model","money","month","moral","motor","mount","movie","music","nerve","night","noble","ocean","offer","olive","onion","opera","orbit","order","organ","other","otter","paddy","paint","panel","panic","paper","parka","party","patch","peach","pearl","pedal","piano","pilot","pitch","pixel","place","plain","plane","plant","plaza","plead","plume","poker","polar","porch","pouch","pound","press","pride","print","prism","prize","proof","proxy","pulse","punch","queen","quest","quiet","quota","quote","radar","rally","ranch","range","raven","reach","react","realm","rebel","reign","relay","remix","rider","ridge","rifle","river","robot","rocky","rogue","royal","ruler","rumor","salad","salsa","salon","satin","scale","scarf","scout","scrap","screw","shade","shaft","shark","sheep","shelf","shell","shine","shiny","shirt","shoal","shore","shout","shrub","sight","silk","skate","skull","slate","slice","slope","smile","smoke","snake","solar","solid","sonar","sound","space","spade","spark","spear","spell","spice","spike","spine","spite","spoon","sport","spray","squad","squid","stack","staff","stage","stain","stair","stamp","stand","stark","stave","steam","steel","steep","stilt","stock","stole","stone","storm","story","strap","straw","strip","stump","style","sugar","suite","sushi","swamp","swarm","sword","table","tango","taste","teach","teeth","tempo","tiger","title","toast","token","tonic","torch","track","trade","trail","train","tramp","trash","treat","trend","trial","tribe","trick","troll","trout","truce","trust","truth","tulip","tunic","tutor","ultra","uncle","union","unity","urban","urine","usage","usher","usual","vague","valor","value","valve","vapor","vault","vegan","venom","verse","vigil","villa","vinyl","viola","viper","vivid","vocal","voice","vowel","wagon","waist","waive","waltz","watch","water","weave","wedge","whale","wheat","wheel","whine","whisk","white","widow","width","wince","windy","witch","witty","woken","world","worry","worth","wrath","wreck","wrist","xerox","yacht","yearn","yeast","yield","young","youth","zebra","zesty","zonal","abide","acorn","actor","adapt","adobe","adopt","adore","affix","after","agent","ahead","aisle","alarm","album","alien","align","alike","alive","alley","allow","alone","alpha","altar","amaze","amber","amend","angel","anger","angle","angry","anvil","apart","apple","apply","apron","arena","argue","arise","armor","aroma","array","arrow","aside","aspen","asset","atlas","attic","audio","audit","aunty","avail","aware","awful","badge","bagel","baker","balmy","banjo","barge","basil","batch","beach","beard","beast","begin","belly","bench","berry","beset","bison","black","blade","blame","blank","blast","blaze","bless","blind","blink","bliss","block","bloom","bluff","blush","board","boast","boney","bonus","boost","botch","bough","bound","brace","brain","brake","brand","brave","bread","break","breed","bribe","brick","bride","brief","bring","brisk","broad","broke","brood","brook","broom","brown","brush","build","bulge","bulky","bunny","burst","cabin","cable","caddy","cagey","camel","canal","candy","cargo","carve","catch","cause","chain","chair","chalk","champ","chant","chaos","charm","chart","cheap","cheat","check","cheek","cheer","chess","chest","chief","child","chili","chill","china","choir","chord","chore","chose","chunk","cider","claim","clash","clasp","class","clean","clear","cleat","clerk","click","cliff","climb","cling","cloak","clock","clone","close","clown","coach","coast","cobra","colic","colon","color","comet","comic","conch","coral","corer","couch","count","craft","crane","crash","crate","crawl","craze","cream"};

const int dico_length = 4;
const char *word_to_find;
char *letters_found;

void choose_word()
{
    srand(time(NULL));
    int index = rand() % dico_length;
    word_to_find = dico[index];
    letters_found = calloc(20, sizeof(char));
}

char get_user_input()
{
    printf("Enter your letter : ");
    char input;
    scanf(" %c", &input);
    while (getchar() != '\n')
        ; // Clear remaining buffer after reading
    return input;
}

void compare_word(int *point, char *letter)
{
    int found = FALSE;
    if (word_to_find == NULL)
        return; // Safety check

    for (size_t i = 0; i < strlen(word_to_find); i++)
    {

        if (tolower(word_to_find[i]) == tolower(letter[0]))
        {
            if (strstr(letters_found, letter) == NULL)
            {
                letters_found[strlen(letters_found)] = letter[0];
            }
            found = TRUE;
        }
    }
    if (found == FALSE)
    {
        (*point)++;
    }
}

int print_letter()
{
    size_t word_length = strlen(word_to_find);
    for (size_t i = 0; i < word_length; i++)
    {
        int print = FALSE;
        for (size_t j = 0; j < strlen(letters_found); j++)
        {
            if (tolower(word_to_find[i]) == tolower(letters_found[j]))
            {
                printf("%c ", word_to_find[i]);
                print = TRUE;
                break;
            }
        }
        if (!print)
        {
            printf("_ ");
        }
    }
    printf("\n");
    if (word_length==strlen(letters_found)){return TRUE;}
    return FALSE;
}