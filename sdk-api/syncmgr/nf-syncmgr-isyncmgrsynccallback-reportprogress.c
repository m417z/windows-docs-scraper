HRESULT ReportProgress(
  [in]  LPCWSTR                 pszItemID,
  [in]  LPCWSTR                 pszProgressText,
  [in]  SYNCMGR_PROGRESS_STATUS nStatus,
  [in]  ULONG                   uCurrentStep,
  [in]  ULONG                   uMaxStep,
  [out] SYNCMGR_CANCEL_REQUEST  *pnCancelRequest
);