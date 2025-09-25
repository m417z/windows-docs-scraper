HRESULT GetEventLogEntryText(
  [in]  LPOLESTR pszEventSource,
  [in]  LPOLESTR pszEventLogName,
  [in]  LPOLESTR pszEventTime,
  [in]  DWORD    dwEventID,
  [out] LPOLESTR *ppszText
);