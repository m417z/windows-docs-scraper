typedef struct {
  ULONG Size;
  ULONG Version;
  BOOL  SupportAgnssInjection;
  ULONG AgnssFormatSupported;
  BYTE  Unused[516];
} GNSS_PLATFORM_CAPABILITY, *PGNSS_PLATFORM_CAPABILITY;