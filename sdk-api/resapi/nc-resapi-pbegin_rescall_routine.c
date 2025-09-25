PBEGIN_RESCALL_ROUTINE PbeginRescallRoutine;

DWORD PbeginRescallRoutine(
  [in]  RESID Resource,
  [in]  DWORD ControlCode,
  [in]  PVOID InBuffer,
  [in]  DWORD InBufferSize,
  [out] PVOID OutBuffer,
  [in]  DWORD OutBufferSize,
  [out] LPDWORD BytesReturned,
  [in]  PRES_CTL_CTX context,
  [out] PBOOL ReturnedAsynchronously
)
{...}