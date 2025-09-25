DXGKCB_REPORT_DIAGNOSTIC DxgkcbReportDiagnostic;

NTSTATUS DxgkcbReportDiagnostic(
  HANDLE DeviceHandle,
  IN_PDXGK_DIAGNOSTIC_HEADER pDiagnostic
)
{...}