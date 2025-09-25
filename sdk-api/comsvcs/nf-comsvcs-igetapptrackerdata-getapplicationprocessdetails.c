HRESULT GetApplicationProcessDetails(
  [in]            REFGUID                       ApplicationInstanceId,
  [in]            DWORD                         ProcessId,
  [in]            DWORD                         Flags,
  [out, optional] ApplicationProcessSummary     *Summary,
  [out, optional] ApplicationProcessStatistics  *Statistics,
  [out, optional] ApplicationProcessRecycleInfo *RecycleInfo,
  [out, optional] BOOL                          *AnyComponentsHangMonitored
);