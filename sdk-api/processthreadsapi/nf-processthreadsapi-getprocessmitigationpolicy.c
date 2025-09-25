BOOL GetProcessMitigationPolicy(
  [in]  HANDLE                    hProcess,
  [in]  PROCESS_MITIGATION_POLICY MitigationPolicy,
  [out] PVOID                     lpBuffer,
  [in]  SIZE_T                    dwLength
);