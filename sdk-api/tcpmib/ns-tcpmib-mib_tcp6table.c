typedef struct _MIB_TCP6TABLE {
  DWORD       dwNumEntries;
  MIB_TCP6ROW table[ANY_SIZE];
} MIB_TCP6TABLE, *PMIB_TCP6TABLE;