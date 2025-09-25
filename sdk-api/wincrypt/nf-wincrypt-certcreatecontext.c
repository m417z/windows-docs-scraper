const void * CertCreateContext(
  [in]           DWORD                     dwContextType,
  [in]           DWORD                     dwEncodingType,
  [in]           const BYTE                *pbEncoded,
  [in]           DWORD                     cbEncoded,
  [in]           DWORD                     dwFlags,
  [in, optional] PCERT_CREATE_CONTEXT_PARA pCreatePara
);