PIMAGE_NT_HEADERS IMAGEAPI CheckSumMappedFile(
  [in]  PVOID  BaseAddress,
  [in]  DWORD  FileLength,
  [out] PDWORD HeaderSum,
  [out] PDWORD CheckSum
);