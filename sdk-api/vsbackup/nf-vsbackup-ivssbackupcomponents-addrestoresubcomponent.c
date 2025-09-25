HRESULT AddRestoreSubcomponent(
  [in] VSS_ID             writerId,
  [in] VSS_COMPONENT_TYPE componentType,
  [in] LPCWSTR            wszLogicalPath,
  [in] LPCWSTR            wszComponentName,
  [in] LPCWSTR            wszSubComponentLogicalPath,
  [in] LPCWSTR            wszSubComponentName,
  [in] bool               bRepair
);