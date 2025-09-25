PRESOURCE_TYPE_CONTROL_ROUTINE PresourceTypeControlRoutine;

DWORD PresourceTypeControlRoutine(
  [in]  LPCWSTR ResourceTypeName,
  [in]  DWORD ControlCode,
  [in]  PVOID InBuffer,
  [in]  DWORD InBufferSize,
  [out] PVOID OutBuffer,
  [in]  DWORD OutBufferSize,
  [out] LPDWORD BytesReturned
)
{...}