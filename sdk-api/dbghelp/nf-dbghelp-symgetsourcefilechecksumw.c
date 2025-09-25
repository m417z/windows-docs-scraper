BOOL IMAGEAPI SymGetSourceFileChecksumW(
  [in]  HANDLE  hProcess,
  [in]  ULONG64 Base,
  [in]  PCWSTR  FileSpec,
  [out] DWORD   *pCheckSumType,
  [out] BYTE    *pChecksum,
  [in]  DWORD   checksumSize,
  [out] DWORD   *pActualBytesWritten
);