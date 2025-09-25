WINHTTPAPI DWORD WinHttpRegisterProxyChangeNotification(
  ULONGLONG                                ullFlags,
  WINHTTP_PROXY_CHANGE_CALLBACK            pfnCallback,
  PVOID                                    pvContext,
  WINHTTP_PROXY_CHANGE_REGISTRATION_HANDLE *hRegistration
);