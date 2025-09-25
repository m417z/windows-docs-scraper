BOOL CryptVerifyTimeStampSignature(
  [in]            const BYTE               *pbTSContentInfo,
                  DWORD                    cbTSContentInfo,
  [in, optional]  const BYTE               *pbData,
                  DWORD                    cbData,
  [in, optional]  HCERTSTORE               hAdditionalStore,
  [out]           PCRYPT_TIMESTAMP_CONTEXT *ppTsContext,
  [out, optional] PCCERT_CONTEXT           *ppTsSigner,
  [out, optional] HCERTSTORE               *phStore
);