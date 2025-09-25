typedef struct tagMULTIKEYHELPA {
#if ...
  DWORD mkSize;
#else
  WORD  mkSize;
#endif
  CHAR  mkKeylist;
  CHAR  szKeyphrase[1];
} MULTIKEYHELPA, *PMULTIKEYHELPA, *LPMULTIKEYHELPA;