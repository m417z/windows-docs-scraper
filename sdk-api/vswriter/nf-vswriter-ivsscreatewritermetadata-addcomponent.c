HRESULT AddComponent(
  [in] VSS_COMPONENT_TYPE ct,
  [in] LPCWSTR            wszLogicalPath,
  [in] LPCWSTR            wszComponentName,
  [in] LPCWSTR            wszCaption,
  [in] const BYTE         *pbIcon,
  [in] UINT               cbIcon,
  [in] bool               bRestoreMetadata,
  [in] bool               bNotifyOnBackupComplete,
  [in] bool               bSelectable,
  [in] bool               bSelectableForRestore,
  [in] DWORD              dwComponentFlags
);