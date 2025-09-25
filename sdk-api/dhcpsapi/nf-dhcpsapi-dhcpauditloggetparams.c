DWORD DhcpAuditLogGetParams(
  [in]  LPWSTR ServerIpAddress,
  [in]  DWORD  Flags,
  [out] LPWSTR *AuditLogDir,
  [out] DWORD  *DiskCheckInterval,
  [out] DWORD  *MaxLogFilesSize,
  [out] DWORD  *MinSpaceOnDisk
);