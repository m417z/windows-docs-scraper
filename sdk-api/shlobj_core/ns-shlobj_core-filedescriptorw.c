typedef struct _FILEDESCRIPTORW {
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
  WCHAR    cFileName[MAX_PATH];
} FILEDESCRIPTORW, *LPFILEDESCRIPTORW;