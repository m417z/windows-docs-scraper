PFN_WER_RUNTIME_EXCEPTION_DEBUGGER_LAUNCH PfnWerRuntimeExceptionDebuggerLaunch;

HRESULT PfnWerRuntimeExceptionDebuggerLaunch(
  [in]      PVOID pContext,
  [in]      const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation,
  [out]     PBOOL pbIsCustomDebugger,
  [out]     PWSTR pwszDebuggerLaunch,
  [in, out] PDWORD pchDebuggerLaunch,
  [out]     PBOOL pbIsDebuggerAutolaunch
)
{...}