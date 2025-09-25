typedef struct _SECURITY_OBJECT {
  PWSTR   pwszName;
  PVOID   pData;
  DWORD   cbData;
  PVOID   pData2;
  DWORD   cbData2;
  DWORD   Id;
  BOOLEAN fWellKnown;
} SECURITY_OBJECT, *PSECURITY_OBJECT;