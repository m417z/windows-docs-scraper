CryptXmlDllVerifySignature Cryptxmldllverifysignature;

HRESULT Cryptxmldllverifysignature(
  [in] const CRYPT_XML_ALGORITHM *pSignatureMethod,
  [in] BCRYPT_KEY_HANDLE hKey,
  [in] const BYTE *pbInput,
  [in] ULONG cbInput,
  [in] const BYTE *pbSignature,
  [in] ULONG cbSignature
)
{...}