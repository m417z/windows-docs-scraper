void WSManReceiveShellOutput(
  [in, out]      WSMAN_SHELL_HANDLE     shell,
  [in, optional] WSMAN_COMMAND_HANDLE   command,
                 DWORD                  flags,
  [in, optional] WSMAN_STREAM_ID_SET    *desiredStreamSet,
  [in]           WSMAN_SHELL_ASYNC      *async,
  [out]          WSMAN_OPERATION_HANDLE *receiveOperation
);