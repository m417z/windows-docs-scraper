HRESULT GetCredential(
  [in]  LPCWSTR          pszUrl,
  [in]  LPCWSTR          pszRealm,
  [in]  DWORD            dwAuthenticationFlags,
  [out] IMFNetCredential **ppCred,
  [out] DWORD            *pdwRequirementsFlags
);