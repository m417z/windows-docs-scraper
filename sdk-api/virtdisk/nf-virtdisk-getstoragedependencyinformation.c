DWORD GetStorageDependencyInformation(
  [in]                HANDLE                      ObjectHandle,
  [in]                GET_STORAGE_DEPENDENCY_FLAG Flags,
  [in]                ULONG                       StorageDependencyInfoSize,
  [in, out]           PSTORAGE_DEPENDENCY_INFO    StorageDependencyInfo,
  [in, out, optional] PULONG                      SizeUsed
);