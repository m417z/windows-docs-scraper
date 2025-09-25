typedef struct _FILEDESCRIPTORA {
  DWORD    dwFlags;
  CLSID    clsid;
  SIZEL    sizel;
  POINTL   pointl;
  DWORD    dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD    nFileSizeHigh;
  DWORD    nFileSizeLow;
  CHAR     cFileName[MAX_PATH];
} FILEDESCRIPTORA, *LPFILEDESCRIPTORA;