DWORD RmAddFilter(
  [in]           DWORD             dwSessionHandle,
  [in, optional] LPCWSTR           strModuleName,
  [in, optional] RM_UNIQUE_PROCESS *pProcess,
  [in, optional] LPCWSTR           strServiceShortName,
  [in]           RM_FILTER_ACTION  FilterAction
);