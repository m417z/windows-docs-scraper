CryptXmlDllSignData Cryptxmldllsigndata;

HRESULT Cryptxmldllsigndata(
  [in]            const CRYPT_XML_ALGORITHM *pSignatureMethod,
  [in]            HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
  [in]            DWORD dwKeySpec,
  [in]            const BYTE *pbInput,
  [in]            ULONG cbInput,
  [out, optional] BYTE *pbOutput,
  [in]            ULONG cbOutput,
  [out]           ULONG *pcbResult
)
{...}