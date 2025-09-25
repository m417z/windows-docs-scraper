UINT MsiCreateTransformSummaryInfoW(
  [in] MSIHANDLE hDatabase,
  [in] MSIHANDLE hDatabaseReference,
  [in] LPCWSTR   szTransformFile,
  [in] int       iErrorConditions,
  [in] int       iValidation
);