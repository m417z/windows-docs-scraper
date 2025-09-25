HRESULT ReportEvent(
  [in]  LPCWSTR             pszItemID,
  [in]  SYNCMGR_EVENT_LEVEL nLevel,
  [in]  SYNCMGR_EVENT_FLAGS nFlags,
  [in]  LPCWSTR             pszName,
  [in]  LPCWSTR             pszDescription,
  [in]  LPCWSTR             pszLinkText,
  [in]  LPCWSTR             pszLinkReference,
  [in]  LPCWSTR             pszContext,
  [out] GUID                *pguidEventID
);