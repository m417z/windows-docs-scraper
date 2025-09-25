DRMEXPORT HRESULT UDAPICALL DRMGetUnboundLicenseObject(
  [in]  DRMQUERYHANDLE hQueryRoot,
  [in]  PWSTR          wszSubObjectType,
  [in]  UINT           iIndex,
  [out] DRMQUERYHANDLE *phSubQuery
);