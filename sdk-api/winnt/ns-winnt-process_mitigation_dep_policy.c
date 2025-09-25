typedef struct _PROCESS_MITIGATION_DEP_POLICY {
  union {
    DWORD Flags;
    struct {
      DWORD Enable : 1;
      DWORD DisableAtlThunkEmulation : 1;
      DWORD ReservedFlags : 30;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  BOOLEAN Permanent;
} PROCESS_MITIGATION_DEP_POLICY, *PPROCESS_MITIGATION_DEP_POLICY;