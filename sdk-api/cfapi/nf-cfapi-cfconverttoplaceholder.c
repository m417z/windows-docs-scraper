HRESULT CfConvertToPlaceholder(
  [in]                HANDLE           FileHandle,
  [in, optional]      LPCVOID          FileIdentity,
  [in]                DWORD            FileIdentityLength,
  [in]                CF_CONVERT_FLAGS ConvertFlags,
  [out, optional]     USN              *ConvertUsn,
  [in, out, optional] LPOVERLAPPED     Overlapped
);