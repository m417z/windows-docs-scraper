typedef struct _MIB_IFTABLE {
  DWORD     dwNumEntries;
  MIB_IFROW table[ANY_SIZE];
} MIB_IFTABLE, *PMIB_IFTABLE;