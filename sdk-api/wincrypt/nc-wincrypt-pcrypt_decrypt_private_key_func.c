PCRYPT_DECRYPT_PRIVATE_KEY_FUNC PcryptDecryptPrivateKeyFunc;

BOOL PcryptDecryptPrivateKeyFunc(
  [in]      CRYPT_ALGORITHM_IDENTIFIER Algorithm,
  [in]      CRYPT_DATA_BLOB EncryptedPrivateKey,
  [out]     BYTE *pbClearTextKey,
  [in, out] DWORD *pcbClearTextKey,
  [in]      LPVOID pVoidDecryptFunc
)
{...}