HRESULT SetFileRestoreStatus(
  [in] VSS_ID                  writerId,
  [in] VSS_COMPONENT_TYPE      ct,
  [in] LPCWSTR                 wszLogicalPath,
  [in] LPCWSTR                 wszComponentName,
  [in] VSS_FILE_RESTORE_STATUS status
);