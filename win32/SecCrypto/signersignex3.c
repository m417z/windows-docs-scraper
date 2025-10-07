HRESULT WINAPI SignerSignEx3(
  _In_       DWORD                  dwFlags,
  _In_       SIGNER_SUBJECT_INFO    *pSubjectInfo,
  _In_       SIGNER_CERT            *pSignerCert,
  _In_       SIGNER_SIGNATURE_INFO  *pSignatureInfo,
  _In_opt_   SIGNER_PROVIDER_INFO   *pProviderInfo,
  _In_opt_   DWORD                  dwTimestampFlags,
  _In_opt_   PCSTR                  pszTimestampAlgorithmOid,
  _In_opt_   PCWSTR                 pwszHttpTimeStamp,
  _In_opt_   PCRYPT_ATTRIBUTES      psRequest,
  _In_opt_   PVOID                  pSipData,
  _Out_      SIGNER_CONTEXT         **ppSignerContext,
  _In_opt_   PCERT_STRONG_SIGN_PARA pCryptoPolicy,
  _In_opt_   SIGNER_DIGEST_SIGN_INFO  *pDigestSignInfo,
  _Reserved_ PVOID                  pReserved
);