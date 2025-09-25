DWORD RmRemoveFilter(
  [in]           DWORD             dwSessionHandle,
  [in, optional] LPCWSTR           strModuleName,
  [in, optional] RM_UNIQUE_PROCESS *pProcess,
  [in, optional] LPCWSTR           strServiceShortName
);