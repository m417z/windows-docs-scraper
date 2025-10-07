typedef struct _MIB_IF_TABLE2 {
  ULONG       NumEntries;
  MIB_IF_ROW2 Table[ANY_SIZE];
} MIB_IF_TABLE2, *PMIB_IF_TABLE2;