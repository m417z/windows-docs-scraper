PBEGIN_RESTYPECALL_ROUTINE PbeginRestypecallRoutine;

DWORD PbeginRestypecallRoutine(
  [in]  LPCWSTR ResourceTypeName,
  [in]  DWORD ControlCode,
  [in]  PVOID InBuffer,
  [in]  DWORD InBufferSize,
  [out] PVOID OutBuffer,
  [in]  DWORD OutBufferSize,
  [out] LPDWORD BytesReturned,
  [in]  PRESTYPE_CTL_CTX context,
  [out] PBOOL ReturnedAsynchronously
)
{...}