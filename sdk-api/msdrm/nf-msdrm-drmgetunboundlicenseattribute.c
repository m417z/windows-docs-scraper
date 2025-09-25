DRMEXPORT HRESULT UDAPICALL DRMGetUnboundLicenseAttribute(
  [in]      DRMQUERYHANDLE  hQueryRoot,
  [in]      PWSTR           wszAttributeType,
  [in]      UINT            iWhich,
  [out]     DRMENCODINGTYPE *peEncoding,
  [in, out] UINT            *pcBuffer,
  [out]     BYTE            *pbBuffer
);