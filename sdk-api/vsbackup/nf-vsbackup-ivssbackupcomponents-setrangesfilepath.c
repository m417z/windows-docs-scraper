HRESULT SetRangesFilePath(
  [in] VSS_ID             writerId,
  [in] VSS_COMPONENT_TYPE ct,
  [in] LPCWSTR            wszLogicalPath,
  [in] LPCWSTR            wszComponentName,
  [in] UINT               iPartialFile,
  [in] LPCWSTR            wszRangesFile
);