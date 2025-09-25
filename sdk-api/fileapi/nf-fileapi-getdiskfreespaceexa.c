BOOL GetDiskFreeSpaceExA(
  [in, optional]  LPCSTR          lpDirectoryName,
  [out, optional] PULARGE_INTEGER lpFreeBytesAvailableToCaller,
  [out, optional] PULARGE_INTEGER lpTotalNumberOfBytes,
  [out, optional] PULARGE_INTEGER lpTotalNumberOfFreeBytes
);