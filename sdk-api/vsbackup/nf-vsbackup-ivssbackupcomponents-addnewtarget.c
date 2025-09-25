HRESULT AddNewTarget(
  [in] VSS_ID             writerId,
  [in] VSS_COMPONENT_TYPE ct,
  [in] LPCWSTR            wszLogicalPath,
  [in] LPCWSTR            wszComponentName,
  [in] LPCWSTR            wszPath,
  [in] LPCWSTR            wszFileName,
  [in] bool               bRecursive,
  [in] LPCWSTR            wszAlternatePath
);