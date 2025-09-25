PSTARTUP_ROUTINE PstartupRoutine;

DWORD PstartupRoutine(
  [in]  LPCWSTR ResourceType,
  [in]  DWORD MinVersionSupported,
  [in]  DWORD MaxVersionSupported,
  [in]  PSET_RESOURCE_STATUS_ROUTINE SetResourceStatus,
  [in]  PLOG_EVENT_ROUTINE LogEvent,
  [out] PCLRES_FUNCTION_TABLE *FunctionTable
)
{...}