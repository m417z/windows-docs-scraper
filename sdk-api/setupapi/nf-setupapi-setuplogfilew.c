WINSETUPAPI BOOL SetupLogFileW(
  [in] HSPFILELOG FileLogHandle,
  [in] PCWSTR     LogSectionName,
  [in] PCWSTR     SourceFilename,
  [in] PCWSTR     TargetFilename,
  [in] DWORD      Checksum,
  [in] PCWSTR     DiskTagfile,
  [in] PCWSTR     DiskDescription,
  [in] PCWSTR     OtherInfo,
  [in] DWORD      Flags
);