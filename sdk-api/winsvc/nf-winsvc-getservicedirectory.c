DWORD GetServiceDirectory(
  SERVICE_STATUS_HANDLE  hServiceStatus,
  SERVICE_DIRECTORY_TYPE eDirectoryType,
  PWCHAR                 lpPathBuffer,
  DWORD                  cchPathBufferLength,
  DWORD                  *lpcchRequiredBufferLength
);