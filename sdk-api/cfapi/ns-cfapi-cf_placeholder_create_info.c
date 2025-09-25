typedef struct CF_PLACEHOLDER_CREATE_INFO {
  LPCWSTR                     RelativeFileName;
  CF_FS_METADATA              FsMetadata;
  LPCVOID                     FileIdentity;
  DWORD                       FileIdentityLength;
  CF_PLACEHOLDER_CREATE_FLAGS Flags;
  HRESULT                     Result;
  USN                         CreateUsn;
} CF_PLACEHOLDER_CREATE_INFO;