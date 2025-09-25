typedef struct _WHEA_XPF_PROCINFO {
  GUID                        CheckInfoId;
  WHEA_XPF_PROCINFO_VALIDBITS ValidBits;
  union {
    WHEA_XPF_CACHE_CHECK CacheCheck;
    WHEA_XPF_TLB_CHECK   TlbCheck;
    WHEA_XPF_BUS_CHECK   BusCheck;
    WHEA_XPF_MS_CHECK    MsCheck;
    ULONGLONG            AsULONGLONG;
  } CheckInfo;
  ULONGLONG                   TargetId;
  ULONGLONG                   RequesterId;
  ULONGLONG                   ResponderId;
  ULONGLONG                   InstructionPointer;
} WHEA_XPF_PROCINFO, *PWHEA_XPF_PROCINFO;