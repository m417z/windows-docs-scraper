_BOOL GetVCPFeatureAndVCPFeatureReply(
  [in]  HANDLE             hMonitor,
  [in]  BYTE               bVCPCode,
  [out] LPMC_VCP_CODE_TYPE pvct,
  [out] LPDWORD            pdwCurrentValue,
  [out] LPDWORD            pdwMaximumValue
);