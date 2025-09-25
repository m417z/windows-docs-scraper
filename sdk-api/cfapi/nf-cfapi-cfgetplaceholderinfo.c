HRESULT CfGetPlaceholderInfo(
  [in]            HANDLE                    FileHandle,
  [in]            CF_PLACEHOLDER_INFO_CLASS InfoClass,
  [out]           PVOID                     InfoBuffer,
  [in]            DWORD                     InfoBufferLength,
  [out, optional] PDWORD                    ReturnedLength
);