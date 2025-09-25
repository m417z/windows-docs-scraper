HRESULT WerReportSubmit(
  [in]            HREPORT            hReportHandle,
  [in]            WER_CONSENT        consent,
  [in]            DWORD              dwFlags,
  [out, optional] PWER_SUBMIT_RESULT pSubmitResult
);