typedef struct _DS_REPL_KCC_DSA_FAILURESW {
  DWORD                    cNumEntries;
  DWORD                    dwReserved;
#if ...
  DS_REPL_KCC_DSA_FAILUREW rgDsaFailure[];
#else
  DS_REPL_KCC_DSA_FAILUREW rgDsaFailure[1];
#endif
} DS_REPL_KCC_DSA_FAILURESW;