void WSManSendShellInput(
  [in]           WSMAN_SHELL_HANDLE     shell,
  [in, optional] WSMAN_COMMAND_HANDLE   command,
                 DWORD                  flags,
  [in]           PCWSTR                 streamId,
  [in]           WSMAN_DATA             *streamData,
                 BOOL                   endOfStream,
  [in]           WSMAN_SHELL_ASYNC      *async,
  [out]          WSMAN_OPERATION_HANDLE *sendOperation
);