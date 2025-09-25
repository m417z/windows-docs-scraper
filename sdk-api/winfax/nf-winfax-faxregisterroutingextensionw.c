WINFAXAPI BOOL FaxRegisterRoutingExtensionW(
  [in] HANDLE                              FaxHandle,
  [in] LPCWSTR                             ExtensionName,
  [in] LPCWSTR                             FriendlyName,
  [in] LPCWSTR                             ImageName,
  [in] PFAX_ROUTING_INSTALLATION_CALLBACKW CallBack,
  [in] LPVOID                              Context
);