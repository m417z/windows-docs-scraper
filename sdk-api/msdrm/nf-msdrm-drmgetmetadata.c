DRMEXPORT HRESULT UDAPICALL DRMGetMetaData(
  [in]                DRMPUBHANDLE hIssuanceLicense,
  [in, out]           UINT         *puContentIdLength,
  [out, optional]     PWSTR        wszContentId,
  [in, out]           UINT         *puContentIdTypeLength,
  [out, optional]     PWSTR        wszContentIdType,
  [in, out, optional] UINT         *puSKUIdLength,
  [out, optional]     PWSTR        wszSKUId,
  [in, out, optional] UINT         *puSKUIdTypeLength,
  [out, optional]     PWSTR        wszSKUIdType,
  [in, out, optional] UINT         *puContentTypeLength,
  [out, optional]     PWSTR        wszContentType,
  [in, out, optional] UINT         *puContentNameLength,
  [out, optional]     PWSTR        wszContentName
);