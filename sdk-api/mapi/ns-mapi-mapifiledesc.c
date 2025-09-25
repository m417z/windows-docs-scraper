typedef struct {
  ULONG  ulReserved;
  ULONG  flFlags;
  ULONG  nPosition;
  LPSTR  lpszPathName;
  LPSTR  lpszFileName;
  LPVOID lpFileType;
} MapiFileDesc, *lpMapiFileDesc;