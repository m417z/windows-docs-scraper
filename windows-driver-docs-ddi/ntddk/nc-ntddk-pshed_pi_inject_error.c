PSHED_PI_INJECT_ERROR PshedPiInjectError;

NTSTATUS PshedPiInjectError(
  [in, out, optional] PVOID PluginContext,
  [in]                ULONGLONG ErrorType,
  [in]                ULONGLONG Parameter1,
  [in]                ULONGLONG Parameter2,
  [in]                ULONGLONG Parameter3,
  [in]                ULONGLONG Parameter4
)
{...}