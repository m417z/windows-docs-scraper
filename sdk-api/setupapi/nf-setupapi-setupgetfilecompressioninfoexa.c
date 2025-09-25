WINSETUPAPI BOOL SetupGetFileCompressionInfoExA(
  [in]      PCSTR  SourceFileName,
  [in, out] PSTR   ActualSourceFileNameBuffer,
  [in, out] DWORD  ActualSourceFileNameBufferLen,
  [out]     PDWORD RequiredBufferLen,
  [out]     PDWORD SourceFileSize,
  [out]     PDWORD TargetFileSize,
  [out]     PUINT  CompressionType
);