PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC PcryptEncryptPrivateKeyFunc;

BOOL PcryptEncryptPrivateKeyFunc(
  [out]     CRYPT_ALGORITHM_IDENTIFIER *pAlgorithm,
  [in]      CRYPT_DATA_BLOB *pClearTextPrivateKey,
  [out]     BYTE *pbEncryptedKey,
  [in, out] DWORD *pcbEncryptedKey,
  [in]      LPVOID pVoidEncryptFunc
)
{...}