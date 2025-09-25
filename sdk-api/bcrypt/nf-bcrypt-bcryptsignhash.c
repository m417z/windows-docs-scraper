NTSTATUS BCryptSignHash(
  [in]            BCRYPT_KEY_HANDLE hKey,
  [in, optional]  VOID              *pPaddingInfo,
  [in, optional]  PUCHAR            pbInput,
  [in]            ULONG             cbInput,
  [out, optional] PUCHAR            pbOutput,
  [in]            ULONG             cbOutput,
  [out]           ULONG             *pcbResult,
  [in]            ULONG             dwFlags
);