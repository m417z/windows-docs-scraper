typedef struct _SP_ALTPLATFORM_INFO_V1 {
  DWORD cbSize;
  DWORD Platform;
  DWORD MajorVersion;
  DWORD MinorVersion;
  WORD  ProcessorArchitecture;
  WORD  Reserved;
} SP_ALTPLATFORM_INFO_V1, *PSP_ALTPLATFORM_INFO_V1;