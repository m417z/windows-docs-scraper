ImportPFXToProvider Importpfxtoprovider;

HRESULT Importpfxtoprovider(
  [in]            HWND hWndParent,
  [in]            BYTE const *pbPFX,
  [in]            DWORD cbPFX,
  [in]            ImportPFXFlags ImportFlags,
  [in, optional]  PCWSTR pwszPassword,
  [in, optional]  PCWSTR pwszProviderName,
  [in, optional]  PCWSTR pwszReaderName,
  [in, optional]  PCWSTR pwszContainerNamePrefix,
  [in, optional]  PCWSTR pwszPin,
  [in, optional]  PCWSTR pwszFriendlyName,
  [out, optional] DWORD *pcCertOut,
  [out, optional] PCCERT_CONTEXT **prgpCertOut
)
{...}