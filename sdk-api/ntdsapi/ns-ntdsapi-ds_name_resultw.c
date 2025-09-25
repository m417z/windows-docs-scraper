typedef struct {
  DWORD                 cItems;
#if ...
  PDS_NAME_RESULT_ITEMW rItems;
#else
  PDS_NAME_RESULT_ITEMW rItems;
#endif
} DS_NAME_RESULTW, *PDS_NAME_RESULTW;