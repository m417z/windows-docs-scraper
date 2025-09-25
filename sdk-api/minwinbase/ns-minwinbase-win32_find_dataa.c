typedef struct _WIN32_FIND_DATAA {
  DWORD    dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD    nFileSizeHigh;
  DWORD    nFileSizeLow;
  DWORD    dwReserved0;
  DWORD    dwReserved1;
  CHAR     cFileName[MAX_PATH];
  CHAR     cAlternateFileName[14];
  DWORD    dwFileType; // Obsolete. Do not use.
  DWORD    dwCreatorType; // Obsolete. Do not use
  WORD     wFinderFlags; // Obsolete. Do not use
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;