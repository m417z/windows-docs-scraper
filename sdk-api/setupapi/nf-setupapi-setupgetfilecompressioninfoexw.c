WINSETUPAPI BOOL SetupGetFileCompressionInfoExW(
  [in]      PCWSTR SourceFileName,
  [in, out] PWSTR  ActualSourceFileNameBuffer,
  [in, out] DWORD  ActualSourceFileNameBufferLen,
  [out]     PDWORD RequiredBufferLen,
  [out]     PDWORD SourceFileSize,
  [out]     PDWORD TargetFileSize,
  [out]     PUINT  CompressionType
);