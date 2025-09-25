HRESULT GetApplicationsInProcess(
  [in]  REFGUID            ApplicationInstanceId,
  [in]  DWORD              ProcessId,
  [in]  REFGUID            PartitionId,
  [in]  DWORD              Flags,
  [out] ULONG              *NumApplicationsInProcess,
  [out] ApplicationSummary **Applications
);