DRMEXPORT HRESULT UDAPICALL DRMVerify(
  [in]      PWSTR         wszData,
  [in, out] UINT          *pcAttestedData,
  [out]     PWSTR         wszAttestedData,
  [out]     DRMATTESTTYPE *peType,
  [in, out] UINT          *pcPrincipal,
  [out]     PWSTR         wszPrincipal,
  [in, out] UINT          *pcManifest,
  [out]     PWSTR         wszManifest
);