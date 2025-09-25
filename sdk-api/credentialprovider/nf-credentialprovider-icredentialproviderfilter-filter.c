HRESULT Filter(
  [in]      CREDENTIAL_PROVIDER_USAGE_SCENARIO cpus,
  [in]      DWORD                              dwFlags,
  [in]      GUID                               *rgclsidProviders,
  [in, out] BOOL                               *rgbAllow,
  [in]      DWORD                              cProviders
);