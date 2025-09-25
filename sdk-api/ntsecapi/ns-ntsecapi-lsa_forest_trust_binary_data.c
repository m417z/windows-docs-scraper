typedef struct _LSA_FOREST_TRUST_BINARY_DATA {
#if ...
  ULONG  Length;
#if ...
  PUCHAR Buffer;
#else
  ULONG  Length;
#endif
#else
  PUCHAR Buffer;
#endif
} LSA_FOREST_TRUST_BINARY_DATA, *PLSA_FOREST_TRUST_BINARY_DATA;