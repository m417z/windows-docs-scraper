BOOL IMAGEAPI SymGetSourceFileChecksum(
  [in]  HANDLE  hProcess,
  [in]  ULONG64 Base,
  [in]  PCSTR   FileSpec,
  [out] DWORD   *pCheckSumType,
  [out] BYTE    *pChecksum,
  [in]  DWORD   checksumSize,
  [out] DWORD   *pActualBytesWritten
);