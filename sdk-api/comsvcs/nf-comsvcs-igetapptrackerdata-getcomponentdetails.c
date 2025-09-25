HRESULT GetComponentDetails(
  [in]  REFGUID                  ApplicationInstanceId,
  [in]  DWORD                    ProcessId,
  [in]  REFCLSID                 Clsid,
  [in]  DWORD                    Flags,
  [out] ComponentSummary         *Summary,
  [out] ComponentStatistics      *Statistics,
  [out] ComponentHangMonitorInfo *HangMonitorInfo
);