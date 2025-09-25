BOOL CertGetCRLContextProperty(
  [in]      PCCRL_CONTEXT pCrlContext,
  [in]      DWORD         dwPropId,
  [out]     void          *pvData,
  [in, out] DWORD         *pcbData
);