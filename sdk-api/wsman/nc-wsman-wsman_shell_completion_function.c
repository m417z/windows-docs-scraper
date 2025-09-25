WSMAN_SHELL_COMPLETION_FUNCTION WsmanShellCompletionFunction;

void WsmanShellCompletionFunction(
  [in, optional] PVOID operationContext,
                 DWORD flags,
  [in]           WSMAN_ERROR *error,
  [in]           WSMAN_SHELL_HANDLE shell,
  [in, optional] WSMAN_COMMAND_HANDLE command,
  [in, optional] WSMAN_OPERATION_HANDLE operationHandle,
  [in, optional] WSMAN_RESPONSE_DATA *data
)
{...}