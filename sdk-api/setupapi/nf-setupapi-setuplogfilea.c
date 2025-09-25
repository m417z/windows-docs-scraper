WINSETUPAPI BOOL SetupLogFileA(
  [in] HSPFILELOG FileLogHandle,
  [in] PCSTR      LogSectionName,
  [in] PCSTR      SourceFilename,
  [in] PCSTR      TargetFilename,
  [in] DWORD      Checksum,
  [in] PCSTR      DiskTagfile,
  [in] PCSTR      DiskDescription,
  [in] PCSTR      OtherInfo,
  [in] DWORD      Flags
);