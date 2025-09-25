PSTARTUP_EX_ROUTINE PstartupExRoutine;

DWORD PstartupExRoutine(
  [in]        LPCWSTR ResourceType,
  [in]        DWORD MinVersionSupported,
  [in]        DWORD MaxVersionSupported,
  [in] [in]   PCLRES_CALLBACK_FUNCTION_TABLE MonitorCallbackFunctions,
  [out] [out] PCLRES_FUNCTION_TABLE *ResourceDllInterfaceFunctions
)
{...}