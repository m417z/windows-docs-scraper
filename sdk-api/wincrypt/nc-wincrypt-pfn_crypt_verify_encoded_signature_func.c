PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC PfnCryptVerifyEncodedSignatureFunc;

BOOL PfnCryptVerifyEncodedSignatureFunc(
  [in]           DWORD dwCertEncodingType,
  [in]           PCERT_PUBLIC_KEY_INFO pPubKeyInfo,
  [in]           PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
  [in, optional] void *pvDecodedSignPara,
  [in]           LPCWSTR pwszCNGPubKeyAlgid,
  [in]           LPCWSTR pwszCNGHashAlgid,
  [in]           BYTE *pbComputedHash,
  [in]           DWORD cbComputedHash,
  [in]           BYTE *pbSignature,
  [in]           DWORD cbSignature
)
{...}