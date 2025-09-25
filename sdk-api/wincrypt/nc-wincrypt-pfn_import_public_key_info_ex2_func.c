PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC PfnImportPublicKeyInfoEx2Func;

BOOL PfnImportPublicKeyInfoEx2Func(
  [in]  DWORD dwCertEncodingType,
  [in]  PCERT_PUBLIC_KEY_INFO pInfo,
  [in]  DWORD dwFlags,
  [in]  void *pvAuxInfo,
  [out] BCRYPT_KEY_HANDLE *phKey
)
{...}