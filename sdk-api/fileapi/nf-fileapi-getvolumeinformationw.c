BOOL GetVolumeInformationW(
  [in, optional]  LPCWSTR lpRootPathName,
  [out, optional] LPWSTR  lpVolumeNameBuffer,
  [in]            DWORD   nVolumeNameSize,
  [out, optional] LPDWORD lpVolumeSerialNumber,
  [out, optional] LPDWORD lpMaximumComponentLength,
  [out, optional] LPDWORD lpFileSystemFlags,
  [out, optional] LPWSTR  lpFileSystemNameBuffer,
  [in]            DWORD   nFileSystemNameSize
);