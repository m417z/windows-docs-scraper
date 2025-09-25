typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
  ULONG_PTR                      ProcessorMask;
  LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
  union {
    struct {
      BYTE Flags;
    } ProcessorCore;
    struct {
      DWORD NodeNumber;
    } NumaNode;
    CACHE_DESCRIPTOR Cache;
    ULONGLONG        Reserved[2];
  } DUMMYUNIONNAME;
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;