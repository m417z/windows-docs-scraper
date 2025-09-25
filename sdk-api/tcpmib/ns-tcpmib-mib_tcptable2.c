typedef struct _MIB_TCPTABLE2 {
  DWORD       dwNumEntries;
  MIB_TCPROW2 table[ANY_SIZE];
} MIB_TCPTABLE2, *PMIB_TCPTABLE2;