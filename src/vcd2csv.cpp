#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vcd2csv.h"
#include "vcddiff/src/libvcd/vcd.h++"

int main(int argc, char **argv) {
  int interval = 1;
  int c;
  char *filename;
  while ((c = getopt(argc, argv, "i:")) != -1) {
    switch (c) {
    case 'i':
      interval = atoi(optarg);
      printf("Accumulating activity over %i-cycle intervals.\n", interval);
      break;
    default:
      break;
    }
  }

  if (argc != optind + 1) {
    // no filename provided
    exit(-1);
  }

  filename = argv[optind++];

  int raise_signals = 0;
  int tspc = 1;

  libvcd::vcd in(filename,raise_signals,tspc);

  int done = 0;

  while (!done) {
    for (int i = 0; i < interval; i++) {
      if (!in.has_more_cycles()) {
	done = 1;
	break;
      }
    }
  }

  return 0;
}
