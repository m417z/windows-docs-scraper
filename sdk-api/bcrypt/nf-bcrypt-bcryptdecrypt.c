NTSTATUS BCryptDecrypt(
  [in, out]           BCRYPT_KEY_HANDLE hKey,
  [in]                PUCHAR            pbInput,
  [in]                ULONG             cbInput,
  [in, optional]      VOID              *pPaddingInfo,
  [in, out, optional] PUCHAR            pbIV,
  [in]                ULONG             cbIV,
  [out, optional]     PUCHAR            pbOutput,
  [in]                ULONG             cbOutput,
  [out]               ULONG             *pcbResult,
  [in]                ULONG             dwFlags
);