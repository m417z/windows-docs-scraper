WSMAN_PLUGIN_AUTHORIZE_OPERATION WsmanPluginAuthorizeOperation;

VOID WsmanPluginAuthorizeOperation(
  [in] PVOID pluginContext,
  [in] WSMAN_SENDER_DETAILS *senderDetails,
  [in] DWORD flags,
  [in] DWORD operation,
  [in] PCWSTR action,
  [in] PCWSTR resourceUri
)
{...}