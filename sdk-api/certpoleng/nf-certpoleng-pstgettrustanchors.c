NTSTATUS PstGetTrustAnchors(
  [in]           PUNICODE_STRING                 pTargetName,
  [in]           DWORD                           cCriteria,
  [in, optional] PCCERT_SELECT_CRITERIA          rgpCriteria,
  [out]          PSecPkgContext_IssuerListInfoEx *ppTrustedIssuers
);