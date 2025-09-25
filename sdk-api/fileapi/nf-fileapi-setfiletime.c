BOOL SetFileTime(
  [in]           HANDLE         hFile,
  [in, optional] const FILETIME *lpCreationTime,
  [in, optional] const FILETIME *lpLastAccessTime,
  [in, optional] const FILETIME *lpLastWriteTime
);