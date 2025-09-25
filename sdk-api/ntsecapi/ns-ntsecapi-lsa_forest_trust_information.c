typedef struct _LSA_FOREST_TRUST_INFORMATION {
#if ...
  ULONG                    RecordCount;
#if ...
  PLSA_FOREST_TRUST_RECORD *Entries;
#else
  ULONG                    RecordCount;
#endif
#else
  PLSA_FOREST_TRUST_RECORD *Entries;
#endif
} LSA_FOREST_TRUST_INFORMATION, *PLSA_FOREST_TRUST_INFORMATION;