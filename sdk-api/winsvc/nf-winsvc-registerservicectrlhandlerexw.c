SERVICE_STATUS_HANDLE RegisterServiceCtrlHandlerExW(
  [in]           LPCWSTR               lpServiceName,
  [in]           LPHANDLER_FUNCTION_EX lpHandlerProc,
  [in, optional] LPVOID                lpContext
);