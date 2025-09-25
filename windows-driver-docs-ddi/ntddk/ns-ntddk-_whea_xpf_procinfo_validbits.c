typedef union _WHEA_XPF_PROCINFO_VALIDBITS {
  struct {
    ULONGLONG CheckInfo : 1;
    ULONGLONG TargetId : 1;
    ULONGLONG RequesterId : 1;
    ULONGLONG ResponderId : 1;
    ULONGLONG InstructionPointer : 1;
    ULONGLONG Reserved : 59;
  } DUMMYSTRUCTNAME;
  ULONGLONG ValidBits;
} WHEA_XPF_PROCINFO_VALIDBITS, *PWHEA_XPF_PROCINFO_VALIDBITS;