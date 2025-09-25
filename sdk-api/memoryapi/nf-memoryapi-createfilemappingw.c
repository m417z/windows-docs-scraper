HANDLE CreateFileMappingW(
  [in]           HANDLE                hFile,
  [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  [in]           DWORD                 flProtect,
  [in]           DWORD                 dwMaximumSizeHigh,
  [in]           DWORD                 dwMaximumSizeLow,
  [in, optional] LPCWSTR               lpName
);