HRESULT WofIsExternalFile(
  [in]                LPCWSTR FilePath,
  [out, optional]     PBOOL   IsExternalFile,
  [out, optional]     PULONG  Provider,
  [out, optional]     PVOID   ExternalFileInfo,
  [in, out, optional] PULONG  BufferLength
);