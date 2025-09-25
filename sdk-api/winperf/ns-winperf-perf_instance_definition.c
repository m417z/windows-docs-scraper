typedef struct _PERF_INSTANCE_DEFINITION {
  DWORD ByteLength;
  DWORD ParentObjectTitleIndex;
  DWORD ParentObjectInstance;
  LONG  UniqueID;
  DWORD NameOffset;
  DWORD NameLength;
} PERF_INSTANCE_DEFINITION, *PPERF_INSTANCE_DEFINITION;