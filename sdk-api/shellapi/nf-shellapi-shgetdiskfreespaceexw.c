BOOL SHGetDiskFreeSpaceExW(
  [in]            LPCWSTR        pszDirectoryName,
  [out, optional] ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
  [out, optional] ULARGE_INTEGER *pulTotalNumberOfBytes,
  [out, optional] ULARGE_INTEGER *pulTotalNumberOfFreeBytes
);