void WSManConnectShellCommand(
  [in, out]      WSMAN_SHELL_HANDLE   shell,
                 DWORD                flags,
  [in]           PCWSTR               commandID,
  [in, optional] WSMAN_OPTION_SET     *options,
  [in, optional] WSMAN_DATA           *connectXml,
  [in]           WSMAN_SHELL_ASYNC    *async,
  [out]          WSMAN_COMMAND_HANDLE *command
);