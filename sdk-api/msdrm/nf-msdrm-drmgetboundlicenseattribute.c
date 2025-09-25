DRMEXPORT HRESULT UDAPICALL DRMGetBoundLicenseAttribute(
  [in]      DRMHANDLE       hQueryRoot,
  [in]      PWSTR           wszAttribute,
  [in]      UINT            iWhich,
  [out]     DRMENCODINGTYPE *peEncoding,
  [in, out] UINT            *pcBuffer,
  [out]     BYTE            *pbBuffer
);