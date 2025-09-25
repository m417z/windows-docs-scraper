PFN_REPORT_SESSION_STATUS PfnReportSessionStatus;

VOID PfnReportSessionStatus(
  [in] HANDLE hMiracastDeviceHandle,
  [in] MIRACAST_STATUS MiracastStatus,
  [in] NTSTATUS Status
)
{...}