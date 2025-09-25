typedef struct _SECPKG_CALL_INFO {
  ULONG ProcessId;
  ULONG ThreadId;
  ULONG Attributes;
  ULONG CallCount;
  PVOID MechOid;
} SECPKG_CALL_INFO, *PSECPKG_CALL_INFO;