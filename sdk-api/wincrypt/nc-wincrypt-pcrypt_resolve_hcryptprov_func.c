PCRYPT_RESOLVE_HCRYPTPROV_FUNC PcryptResolveHcryptprovFunc;

BOOL PcryptResolveHcryptprovFunc(
  [in]  CRYPT_PRIVATE_KEY_INFO *pPrivateKeyInfo,
  [out] HCRYPTPROV *phCryptProv,
  [in]  LPVOID pVoidResolveFunc
)
{...}