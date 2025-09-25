WINHTTPAPI WINHTTP_STATUS_CALLBACK WinHttpSetStatusCallback(
  [in] HINTERNET               hInternet,
  [in] WINHTTP_STATUS_CALLBACK lpfnInternetCallback,
  [in] DWORD                   dwNotificationFlags,
  [in] DWORD_PTR               dwReserved
);