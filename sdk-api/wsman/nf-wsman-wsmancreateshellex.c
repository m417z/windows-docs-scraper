void WSManCreateShellEx(
  [in, out]      WSMAN_SESSION_HANDLE     session,
                 DWORD                    flags,
  [in]           PCWSTR                   resourceUri,
  [in]           PCWSTR                   shellId,
  [in, optional] WSMAN_SHELL_STARTUP_INFO *startupInfo,
  [in, optional] WSMAN_OPTION_SET         *options,
  [in, optional] WSMAN_DATA               *createXml,
  [in]           WSMAN_SHELL_ASYNC        *async,
  [out]          WSMAN_SHELL_HANDLE       *shell
);