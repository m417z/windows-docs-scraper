WINSETUPAPI DWORD SetupGetFileCompressionInfoW(
  [in]      PCWSTR SourceFileName,
  [in, out] PWSTR  *ActualSourceFileName,
  [in, out] PDWORD SourceFileSize,
  [in, out] PDWORD TargetFileSize,
  [in, out] PUINT  CompressionType
);