WINSETUPAPI DWORD SetupGetFileCompressionInfoA(
  [in]      PCSTR  SourceFileName,
  [in, out] PSTR   *ActualSourceFileName,
  [in, out] PDWORD SourceFileSize,
  [in, out] PDWORD TargetFileSize,
  [in, out] PUINT  CompressionType
);