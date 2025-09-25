WSMAN_PLUGIN_COMMAND WsmanPluginCommand;

VOID WsmanPluginCommand(
  WSMAN_PLUGIN_REQUEST *requestDetails,
  DWORD flags,
  PVOID shellContext,
  PCWSTR commandLine,
  WSMAN_COMMAND_ARG_SET *arguments
)
{...}