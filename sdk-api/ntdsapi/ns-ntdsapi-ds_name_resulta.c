typedef struct {
  DWORD                 cItems;
#if ...
  PDS_NAME_RESULT_ITEMA rItems;
#else
  PDS_NAME_RESULT_ITEMA rItems;
#endif
} DS_NAME_RESULTA, *PDS_NAME_RESULTA;