typedef struct _PROCESS_MITIGATION_ASLR_POLICY {
  union {
    DWORD Flags;
    struct {
      DWORD EnableBottomUpRandomization : 1;
      DWORD EnableForceRelocateImages : 1;
      DWORD EnableHighEntropy : 1;
      DWORD DisallowStrippedImages : 1;
      DWORD ReservedFlags : 28;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_ASLR_POLICY, *PPROCESS_MITIGATION_ASLR_POLICY;