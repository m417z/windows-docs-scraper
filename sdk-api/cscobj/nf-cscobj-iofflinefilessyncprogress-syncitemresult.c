HRESULT SyncItemResult(
  [in]  LPCWSTR                    pszFile,
  [in]  HRESULT                    hrResult,
  [in]  IOfflineFilesSyncErrorInfo *pErrorInfo,
  [out] OFFLINEFILES_OP_RESPONSE   *pResponse
);