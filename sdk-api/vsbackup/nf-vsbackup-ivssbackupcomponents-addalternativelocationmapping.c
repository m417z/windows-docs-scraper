HRESULT AddAlternativeLocationMapping(
  [in] VSS_ID             writerId,
  [in] VSS_COMPONENT_TYPE componentType,
  [in] LPCWSTR            wszLogicalPath,
  [in] LPCWSTR            wszComponentName,
  [in] LPCWSTR            wszPath,
  [in] LPCWSTR            wszFilespec,
  [in] bool               bRecursive,
  [in] LPCWSTR            wszDestination
);