SERVICE_STATUS_HANDLE RegisterServiceCtrlHandlerExA(
  [in]           LPCSTR                lpServiceName,
  [in]           LPHANDLER_FUNCTION_EX lpHandlerProc,
  [in, optional] LPVOID                lpContext
);