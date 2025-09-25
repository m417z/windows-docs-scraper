typedef struct _MIB_UDP6TABLE {
  DWORD       dwNumEntries;
  MIB_UDP6ROW table[ANY_SIZE];
} MIB_UDP6TABLE, *PMIB_UDP6TABLE;