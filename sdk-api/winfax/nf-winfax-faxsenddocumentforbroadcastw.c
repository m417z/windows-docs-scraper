WINFAXAPI BOOL FaxSendDocumentForBroadcastW(
  [in]  HANDLE                   FaxHandle,
  [in]  LPCWSTR                  FileName,
  [out] LPDWORD                  FaxJobId,
  [in]  PFAX_RECIPIENT_CALLBACKW FaxRecipientCallback,
  [in]  LPVOID                   Context
);