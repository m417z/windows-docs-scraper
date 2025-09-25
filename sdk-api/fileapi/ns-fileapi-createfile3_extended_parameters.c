typedef struct _CREATEFILE3_EXTENDED_PARAMETERS {
  DWORD                 dwSize;
  DWORD                 dwFileAttributes;
  DWORD                 dwFileFlags;
  DWORD                 dwSecurityQosFlags;
  LPSECURITY_ATTRIBUTES lpSecurityAttributes;
  HANDLE                hTemplateFile;
} CREATEFILE3_EXTENDED_PARAMETERS, *PCREATEFILE3_EXTENDED_PARAMETERS, *LPCREATEFILE3_EXTENDED_PARAMETERS;