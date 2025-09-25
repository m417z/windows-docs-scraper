typedef struct _STORAGE_DIAGNOSTIC_MP_REQUEST {
  ULONG                             Version;
  ULONG                             Size;
  MP_STORAGE_DIAGNOSTIC_TARGET_TYPE TargetType;
  MP_STORAGE_DIAGNOSTIC_LEVEL       Level;
  GUID                              ProviderId;
  ULONG                             BufferSize;
  ULONG                             Reserved;
  UCHAR                             DataBuffer[ANYSIZE_ARRAY];
} STORAGE_DIAGNOSTIC_MP_REQUEST, *PSTORAGE_DIAGNOSTIC_MP_REQUEST;