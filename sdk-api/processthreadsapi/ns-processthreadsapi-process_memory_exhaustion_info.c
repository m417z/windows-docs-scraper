typedef struct _PROCESS_MEMORY_EXHAUSTION_INFO {
  USHORT                         Version;
  USHORT                         Reserved;
  PROCESS_MEMORY_EXHAUSTION_TYPE Type;
  ULONG_PTR                      Value;
} PROCESS_MEMORY_EXHAUSTION_INFO, *PPROCESS_MEMORY_EXHAUSTION_INFO;