typedef struct _PROCESS_MITIGATION_FONT_DISABLE_POLICY {
  union {
    DWORD Flags;
    struct {
      DWORD DisableNonSystemFonts : 1;
      DWORD AuditNonSystemFontLoading : 1;
      DWORD ReservedFlags : 30;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} PROCESS_MITIGATION_FONT_DISABLE_POLICY, *PPROCESS_MITIGATION_FONT_DISABLE_POLICY;