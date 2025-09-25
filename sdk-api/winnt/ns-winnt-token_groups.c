typedef struct _TOKEN_GROUPS {
  DWORD              GroupCount;
#if ...
  SID_AND_ATTRIBUTES *Groups[];
#else
  SID_AND_ATTRIBUTES Groups[ANYSIZE_ARRAY];
#endif
} TOKEN_GROUPS, *PTOKEN_GROUPS;