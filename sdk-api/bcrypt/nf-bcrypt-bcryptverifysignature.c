NTSTATUS BCryptVerifySignature(
  [in]           BCRYPT_KEY_HANDLE hKey,
  [in, optional] VOID              *pPaddingInfo,
  [in, optional] PUCHAR            pbHash,
  [in]           ULONG             cbHash,
  [in]           PUCHAR            pbSignature,
  [in]           ULONG             cbSignature,
  [in]           ULONG             dwFlags
);