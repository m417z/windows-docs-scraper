WSMAN_PLUGIN_SEND WsmanPluginSend;

VOID WsmanPluginSend(
  WSMAN_PLUGIN_REQUEST *requestDetails,
  DWORD flags,
  PVOID shellContext,
  PVOID commandContext,
  PCWSTR stream,
  WSMAN_DATA *inboundData
)
{...}