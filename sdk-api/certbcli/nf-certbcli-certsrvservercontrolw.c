HRESULT CERTBCLI_API CertSrvServerControlW(
  [in]  WCHAR const *pwszServerName,
  [in]  DWORD       dwControlFlags,
  [out] DWORD       *pcbOut,
  [out] BYTE        **ppbOut
);