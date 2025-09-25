DWORD GetSharedServiceDirectory(
  SC_HANDLE                     ServiceHandle,
  SERVICE_SHARED_DIRECTORY_TYPE DirectoryType,
  PWCHAR                        PathBuffer,
  DWORD                         PathBufferLength,
  DWORD                         *RequiredBufferLength
);