DWORD WSAAPI WSAWaitForMultipleEvents(
  [in] DWORD          cEvents,
  [in] const WSAEVENT *lphEvents,
  [in] BOOL           fWaitAll,
  [in] DWORD          dwTimeout,
  [in] BOOL           fAlertable
);