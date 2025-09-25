void WSManRunShellCommand(
  [in, out]      WSMAN_SHELL_HANDLE    shell,
                 DWORD                 flags,
  [in]           PCWSTR                commandLine,
  [in, optional] WSMAN_COMMAND_ARG_SET *args,
  [in, optional] WSMAN_OPTION_SET      *options,
  [in]           WSMAN_SHELL_ASYNC     *async,
  [out]          WSMAN_COMMAND_HANDLE  *command
);