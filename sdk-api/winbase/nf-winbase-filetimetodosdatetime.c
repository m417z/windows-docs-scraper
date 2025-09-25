BOOL FileTimeToDosDateTime(
  [in]  const FILETIME *lpFileTime,
  [out] LPWORD         lpFatDate,
  [out] LPWORD         lpFatTime
);