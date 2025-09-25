HRESULT CfConnectSyncRoot(
  [in]           LPCWSTR                        SyncRootPath,
  [in]           const CF_CALLBACK_REGISTRATION *CallbackTable,
  [in, optional] LPCVOID                        CallbackContext,
  [in]           CF_CONNECT_FLAGS               ConnectFlags,
  [out]          CF_CONNECTION_KEY              *ConnectionKey
);