typedef struct _LSA_FOREST_TRUST_COLLISION_RECORD {
  ULONG                                  Index;
  LSA_FOREST_TRUST_COLLISION_RECORD_TYPE Type;
  ULONG                                  Flags;
  LSA_UNICODE_STRING                     Name;
} LSA_FOREST_TRUST_COLLISION_RECORD, *PLSA_FOREST_TRUST_COLLISION_RECORD;