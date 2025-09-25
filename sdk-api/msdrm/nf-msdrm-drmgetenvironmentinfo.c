DRMEXPORT HRESULT UDAPICALL DRMGetEnvironmentInfo(
  [in]      DRMENVHANDLE    handle,
  [in]      PWSTR           wszAttribute,
  [out]     DRMENCODINGTYPE *peEncoding,
  [in, out] UINT            *pcBuffer,
  [out]     BYTE            *pbBuffer
);