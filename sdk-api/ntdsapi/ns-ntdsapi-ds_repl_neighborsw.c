typedef struct _DS_REPL_NEIGHBORSW {
  DWORD             cNumNeighbors;
  DWORD             dwReserved;
#if ...
  DS_REPL_NEIGHBORW rgNeighbor[];
#else
  DS_REPL_NEIGHBORW rgNeighbor[1];
#endif
} DS_REPL_NEIGHBORSW;