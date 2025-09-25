PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC PfnCryptExportPublicKeyInfoEx2Func;

BOOL PfnCryptExportPublicKeyInfoEx2Func(
  [in]            NCRYPT_KEY_HANDLE hNCryptKey,
  [in]            DWORD dwCertEncodingType,
  [in]            LPSTR pszPublicKeyObjId,
  [in]            DWORD dwFlags,
  [in, optional]  void *pvAuxInfo,
  [out, optional] PCERT_PUBLIC_KEY_INFO pInfo,
  [in, out]       DWORD *pcbInfo
)
{...}