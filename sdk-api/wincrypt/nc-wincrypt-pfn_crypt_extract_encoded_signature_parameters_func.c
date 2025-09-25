PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC PfnCryptExtractEncodedSignatureParametersFunc;

BOOL PfnCryptExtractEncodedSignatureParametersFunc(
  [in]            DWORD dwCertEncodingType,
  [in]            PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
  [out, optional] void **ppvDecodedSignPara,
  [out]           LPWSTR *ppwszCNGHashAlgid
)
{...}