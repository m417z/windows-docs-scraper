DWORD RmRegisterResources(
  [in]           DWORD                dwSessionHandle,
  [in]           UINT                 nFiles,
  [in, optional] LPCWSTR []           rgsFileNames,
  [in]           UINT                 nApplications,
  [in, optional] RM_UNIQUE_PROCESS [] rgApplications,
  [in]           UINT                 nServices,
  [in, optional] LPCWSTR []           rgsServiceNames
);