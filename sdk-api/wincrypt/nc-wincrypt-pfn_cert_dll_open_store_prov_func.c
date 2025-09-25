PFN_CERT_DLL_OPEN_STORE_PROV_FUNC PfnCertDllOpenStoreProvFunc;

BOOL PfnCertDllOpenStoreProvFunc(
  [in]      LPCSTR lpszStoreProvider,
  [in]      DWORD dwEncodingType,
  [in]      HCRYPTPROV_LEGACY hCryptProv,
  [in]      DWORD dwFlags,
  [in]      const void *pvPara,
  [in]      HCERTSTORE hCertStore,
  [in, out] PCERT_STORE_PROV_INFO pStoreProvInfo
)
{...}