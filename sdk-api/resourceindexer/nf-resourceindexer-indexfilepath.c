HRESULT IndexFilePath(
  [in]  PVOID                    resourceIndexer,
  [in]  PCWSTR                   filePath,
  [out] PWSTR                    *ppResourceUri,
  [out] ULONG                    *pQualifierCount,
  [out] IndexedResourceQualifier **ppQualifiers
);