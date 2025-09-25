DRMEXPORT HRESULT UDAPICALL DRMAttest(
  [in]      DRMHANDLE     hEnablingPrincipal,
  [in]      PWSTR         wszData,
  [in]      DRMATTESTTYPE eType,
  [in, out] UINT          *pcAttestedBlob,
  [out]     PWSTR         wszAttestedBlob
);