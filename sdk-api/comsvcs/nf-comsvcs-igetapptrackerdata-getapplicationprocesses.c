HRESULT GetApplicationProcesses(
  [in]  REFGUID                   PartitionId,
  [in]  REFGUID                   ApplicationId,
  [in]  DWORD                     Flags,
  [out] ULONG                     *NumApplicationProcesses,
  [out] ApplicationProcessSummary **ApplicationProcesses
);