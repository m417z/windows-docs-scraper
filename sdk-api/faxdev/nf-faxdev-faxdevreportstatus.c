BOOL FaxDevReportStatus(
  [in]  HANDLE          FaxHandle,
  [out] PFAX_DEV_STATUS FaxStatus,
  [in]  DWORD           FaxStatusSize,
  [out] LPDWORD         FaxStatusSizeRequired
);