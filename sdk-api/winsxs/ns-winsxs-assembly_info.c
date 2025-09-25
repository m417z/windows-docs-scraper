typedef struct _ASSEMBLY_INFO {
  ULONG          cbAssemblyInfo;
  DWORD          dwAssemblyFlags;
  ULARGE_INTEGER uliAssemblySizeInKB;
  LPWSTR         pszCurrentAssemblyPathBuf;
  ULONG          cchBuf;
} ASSEMBLY_INFO;