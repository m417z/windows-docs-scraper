typedef struct tagPXE_PROVIDER {
  ULONG  uSizeOfStruct;
  LPWSTR pwszName;
  LPWSTR pwszFilePath;
  BOOL   bIsCritical;
  ULONG  uIndex;
} PXE_PROVIDER, *PPXE_PROVIDER;