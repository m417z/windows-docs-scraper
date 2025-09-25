WINFAXAPI BOOL FaxSendDocumentForBroadcastA(
  [in]  HANDLE                   FaxHandle,
  [in]  LPCSTR                   FileName,
  [out] LPDWORD                  FaxJobId,
  [in]  PFAX_RECIPIENT_CALLBACKA FaxRecipientCallback,
  [in]  LPVOID                   Context
);