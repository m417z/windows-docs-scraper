typedef struct _TR_SECURE_DEPENDENCY_V1 {
  TR_SECURE_DEPENDENCY_TYPE Type;
  ULONG                     MaxRequired;
  GUID                      Id;
} TR_SECURE_DEPENDENCY_V1, *PTR_SECURE_DEPENDENCY_V1;