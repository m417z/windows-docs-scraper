BOOL GetDiskFreeSpaceExW(
  [in, optional]  LPCWSTR         lpDirectoryName,
  [out, optional] PULARGE_INTEGER lpFreeBytesAvailableToCaller,
  [out, optional] PULARGE_INTEGER lpTotalNumberOfBytes,
  [out, optional] PULARGE_INTEGER lpTotalNumberOfFreeBytes
);