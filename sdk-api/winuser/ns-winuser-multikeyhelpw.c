typedef struct tagMULTIKEYHELPW {
#if ...
  DWORD mkSize;
#else
  WORD  mkSize;
#endif
  WCHAR mkKeylist;
  WCHAR szKeyphrase[1];
} MULTIKEYHELPW, *PMULTIKEYHELPW, *LPMULTIKEYHELPW;