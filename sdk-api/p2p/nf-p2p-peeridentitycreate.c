NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerIdentityCreate(
  [in]  PCWSTR     pwzClassifier,
  [in]  PCWSTR     pwzFriendlyName,
  [in]  HCRYPTPROV hCryptProv,
  [out] PWSTR      *ppwzIdentity
);