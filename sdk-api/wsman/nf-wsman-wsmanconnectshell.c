void WSManConnectShell(
  [in, out]      WSMAN_SESSION_HANDLE session,
                 DWORD                flags,
  [in]           PCWSTR               resourceUri,
  [in]           PCWSTR               shellID,
  [in, optional] WSMAN_OPTION_SET     *options,
  [in, optional] WSMAN_DATA           *connectXml,
  [in]           WSMAN_SHELL_ASYNC    *async,
  [out]          WSMAN_SHELL_HANDLE   *shell
);