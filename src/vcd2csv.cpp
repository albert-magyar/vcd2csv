#include 

int main(int argc, char **argv) {
  while ( (c = getopt(argc, argv, "i:")) != -1) {
    switch (c) {
    case 'i':
      printf ("option c with value '%s'\n", optarg);
      break;
    default:
      printf ("?? getopt returned character code 0%o ??\n", c);
    }
  }
  return 0;
}
