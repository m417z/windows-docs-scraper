typedef struct _FILE_NAME_INFO {
  DWORD FileNameLength;
  WCHAR FileName[1];
} FILE_NAME_INFO, *PFILE_NAME_INFO;