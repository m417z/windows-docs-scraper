WSMAN_PLUGIN_RECEIVE WsmanPluginReceive;

VOID WsmanPluginReceive(
  WSMAN_PLUGIN_REQUEST *requestDetails,
  DWORD flags,
  PVOID shellContext,
  PVOID commandContext,
  WSMAN_STREAM_ID_SET *streamSet
)
{...}