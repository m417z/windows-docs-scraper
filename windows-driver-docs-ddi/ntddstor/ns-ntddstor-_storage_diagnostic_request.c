typedef struct _STORAGE_DIAGNOSTIC_REQUEST {
  ULONG                          Version;
  ULONG                          Size;
  ULONG                          Flags;
  STORAGE_DIAGNOSTIC_TARGET_TYPE TargetType;
  STORAGE_DIAGNOSTIC_LEVEL       Level;
} STORAGE_DIAGNOSTIC_REQUEST, *PSTORAGE_DIAGNOSTIC_REQUEST;