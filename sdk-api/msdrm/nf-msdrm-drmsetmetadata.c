DRMEXPORT HRESULT UDAPICALL DRMSetMetaData(
  [in]           DRMPUBHANDLE hIssuanceLicense,
  [in]           PWSTR        wszContentId,
  [in]           PWSTR        wszContentIdType,
  [in, optional] PWSTR        wszSKUId,
  [in, optional] PWSTR        wszSKUIdType,
  [in, optional] PWSTR        wszContentType,
  [in, optional] PWSTR        wszContentName
);