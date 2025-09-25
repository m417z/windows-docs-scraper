typedef struct WINTRUST_FILE_INFO_ {
  DWORD   cbStruct;
  LPCWSTR pcwszFilePath;
  HANDLE  hFile;
  GUID    *pgKnownSubject;
} WINTRUST_FILE_INFO, *PWINTRUST_FILE_INFO;