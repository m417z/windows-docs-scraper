DRMEXPORT HRESULT UDAPICALL DRMGetBoundLicenseObject(
  [in]  DRMHANDLE hQueryRoot,
  [in]  PWSTR     wszSubObjectType,
  [in]  UINT      iWhich,
  [out] DRMHANDLE *phSubObject
);