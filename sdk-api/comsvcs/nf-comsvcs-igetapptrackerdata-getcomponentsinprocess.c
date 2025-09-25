HRESULT GetComponentsInProcess(
  [in]  REFGUID          ApplicationInstanceId,
  [in]  DWORD            ProcessId,
  [in]  REFGUID          PartitionId,
  [in]  REFGUID          ApplicationId,
  [in]  DWORD            Flags,
  [out] ULONG            *NumComponentsInProcess,
  [out] ComponentSummary **Components
);