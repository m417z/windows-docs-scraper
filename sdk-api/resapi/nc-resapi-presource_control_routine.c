PRESOURCE_CONTROL_ROUTINE PresourceControlRoutine;

DWORD PresourceControlRoutine(
  [in]            RESID Resource,
  [in]            DWORD ControlCode,
  [in, optional]  PVOID InBuffer,
  [in]            DWORD InBufferSize,
  [out, optional] PVOID OutBuffer,
  [in]            DWORD OutBufferSize,
  [out]           LPDWORD BytesReturned
)
{...}