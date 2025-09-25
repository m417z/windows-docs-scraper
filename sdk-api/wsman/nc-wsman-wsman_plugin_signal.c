WSMAN_PLUGIN_SIGNAL WsmanPluginSignal;

VOID WsmanPluginSignal(
  [in]           WSMAN_PLUGIN_REQUEST *requestDetails,
  [in]           DWORD flags,
  [in]           PVOID shellContext,
  [in, optional] PVOID commandContext,
  [in]           PCWSTR code
)
{...}