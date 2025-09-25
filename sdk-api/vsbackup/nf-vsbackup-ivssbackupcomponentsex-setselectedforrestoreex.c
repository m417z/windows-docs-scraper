HRESULT SetSelectedForRestoreEx(
  [in] VSS_ID             writerId,
  [in] VSS_COMPONENT_TYPE ct,
  [in] LPCWSTR            wszLogicalPath,
  [in] LPCWSTR            wszComponentName,
  [in] bool               bSelectedForRestore,
  [in] VSS_ID             instanceId
);