HRESULT CfGetPlaceholderRangeInfo(
  [in]            HANDLE                          FileHandle,
  [in]            CF_PLACEHOLDER_RANGE_INFO_CLASS InfoClass,
  [in]            LARGE_INTEGER                   StartingOffset,
  [in]            LARGE_INTEGER                   Length,
  [out]           PVOID                           InfoBuffer,
  [in]            DWORD                           InfoBufferLength,
  [out, optional] PDWORD                          ReturnedLength
);