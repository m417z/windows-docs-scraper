HRESULT ResolvePersonalDesktop(
  [in]  const wchar_t                   *userId,
  [in]  const wchar_t                   *poolId,
  [in]  TSPUB_PLUGIN_PD_RESOLUTION_TYPE ePdResolutionType,
  [out] TSPUB_PLUGIN_PD_ASSIGNMENT_TYPE *pPdAssignmentType,
  [out] wchar_t [256]                   endPointName
);