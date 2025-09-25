typedef struct {
  ULONG ulReserved;
  ULONG flFlags;
  ULONG nPosition;
  PWSTR lpszPathName;
  PWSTR lpszFileName;
  PVOID lpFileType;
} MapiFileDescW, *lpMapiFileDescW;