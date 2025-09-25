BOOL GetVolumeInformationA(
  [in, optional]  LPCSTR  lpRootPathName,
  [out, optional] LPSTR   lpVolumeNameBuffer,
  [in]            DWORD   nVolumeNameSize,
  [out, optional] LPDWORD lpVolumeSerialNumber,
  [out, optional] LPDWORD lpMaximumComponentLength,
  [out, optional] LPDWORD lpFileSystemFlags,
  [out, optional] LPSTR   lpFileSystemNameBuffer,
  [in]            DWORD   nFileSystemNameSize
);