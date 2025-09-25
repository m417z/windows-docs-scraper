typedef struct _MIB_TCPTABLE {
  DWORD      dwNumEntries;
  MIB_TCPROW table[ANY_SIZE];
} MIB_TCPTABLE, *PMIB_TCPTABLE;