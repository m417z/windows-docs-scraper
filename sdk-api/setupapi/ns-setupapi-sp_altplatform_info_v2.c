typedef struct _SP_ALTPLATFORM_INFO_V2 {
  DWORD cbSize;
  DWORD Platform;
  DWORD MajorVersion;
  DWORD MinorVersion;
  WORD  ProcessorArchitecture;
  union {
    WORD Reserved;
    WORD Flags;
  } DUMMYUNIONNAME;
  DWORD FirstValidatedMajorVersion;
  DWORD FirstValidatedMinorVersion;
} SP_ALTPLATFORM_INFO_V2, *PSP_ALTPLATFORM_INFO_V2;