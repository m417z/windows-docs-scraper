BOOL GetFileTime(
  [in]            HANDLE     hFile,
  [out, optional] LPFILETIME lpCreationTime,
  [out, optional] LPFILETIME lpLastAccessTime,
  [out, optional] LPFILETIME lpLastWriteTime
);