void WSManSignalShell(
  [in]           WSMAN_SHELL_HANDLE     shell,
  [in, optional] WSMAN_COMMAND_HANDLE   command,
                 DWORD                  flags,
  [in]           PCWSTR                 code,
  [in]           WSMAN_SHELL_ASYNC      *async,
  [out]          WSMAN_OPERATION_HANDLE *signalOperation
);