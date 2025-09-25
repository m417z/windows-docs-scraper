typedef struct XAPO_REGISTRATION_PROPERTIES {
  CLSID  clsid;
  WCHAR  FriendlyName[XAPO_REGISTRATION_STRING_LENGTH];
  WCHAR  CopyrightInfo[XAPO_REGISTRATION_STRING_LENGTH];
  UINT32 MajorVersion;
  UINT32 MinorVersion;
  UINT32 Flags;
  UINT32 MinInputBufferCount;
  UINT32 MaxInputBufferCount;
  UINT32 MinOutputBufferCount;
  UINT32 MaxOutputBufferCount;
} XAPO_REGISTRATION_PROPERTIES;