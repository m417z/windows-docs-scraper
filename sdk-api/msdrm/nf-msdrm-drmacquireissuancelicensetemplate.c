DRMEXPORT HRESULT UDAPICALL DRMAcquireIssuanceLicenseTemplate(
  [in]           DRMHSESSION hClient,
  [in]           UINT        uFlags,
  [in]           VOID        *pvReserved,
  [in]           UINT        cTemplates,
  [in, optional] PWSTR       *pwszTemplateIds,
  [in]           PWSTR       wszUrl,
  [in]           VOID        *pvContext
);