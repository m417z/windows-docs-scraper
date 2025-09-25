PFNCFILTERPROC Pfncfilterproc;

BOOL Pfncfilterproc(
  [in] PCCERT_CONTEXT pCertContext,
  [in] BOOL *pfInitialSelectedCert,
  [in] void *pvCallbackData
)
{...}