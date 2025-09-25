DWORD WSManPluginReceiveResult(
  [in]           WSMAN_PLUGIN_REQUEST *requestDetails,
  [in]           DWORD                flags,
  [in, optional] PCWSTR               stream,
  [in, optional] WSMAN_DATA           *streamResult,
  [in, optional] PCWSTR               commandState,
  [in]           DWORD                exitCode
);