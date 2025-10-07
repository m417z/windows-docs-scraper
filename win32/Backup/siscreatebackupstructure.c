BOOL SisCreateBackupStructure(
  _In_  PWCHAR volumeRoot,
  _Out_ PVOID  *sisBackupStructure,
  _Out_ PWCHAR *commonStoreRootPathname,
  _Out_ PULONG countOfCommonStoreFilesToBackUp,
  _Out_ PWCHAR **commonStoreFilesToBackUp
);