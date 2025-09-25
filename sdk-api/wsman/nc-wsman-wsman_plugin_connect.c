WSMAN_PLUGIN_CONNECT WsmanPluginConnect;

VOID WsmanPluginConnect(
  [in]           WSMAN_PLUGIN_REQUEST *requestDetails,
  [in]           DWORD flags,
  [in]           PVOID shellContext,
  [in, optional] PVOID commandContext,
  [in, optional] WSMAN_DATA *inboundConnectInformation
)
{...}