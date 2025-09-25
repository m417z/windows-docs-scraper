PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC PfnCryptSignAndEncodeHashFunc;

BOOL PfnCryptSignAndEncodeHashFunc(
  [in]      NCRYPT_KEY_HANDLE hKey,
  [in]      DWORD dwCertEncodingType,
  [in]      PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
  [in]      void *pvDecodedSignPara,
  [in]      LPCWSTR pwszCNGPubKeyAlgid,
  [in]      LPCWSTR pwszCNGHashAlgid,
  [in]      BYTE *pbComputedHash,
  [in]      DWORD cbComputedHash,
  [out]     BYTE *pbSignature,
  [in, out] DWORD *pcbSignature
)
{...}