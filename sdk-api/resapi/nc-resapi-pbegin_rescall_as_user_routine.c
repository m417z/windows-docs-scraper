PBEGIN_RESCALL_AS_USER_ROUTINE PbeginRescallAsUserRoutine;

DWORD PbeginRescallAsUserRoutine(
  [in] [in]           RESID Resource,
  [in] [in]           HANDLE TokenHandle,
  [in] [in]           DWORD ControlCode,
  [in] [in]           PVOID InBuffer,
  [in] [in]           DWORD InBufferSize,
  [out] [out]         PVOID OutBuffer,
  [in] [in]           DWORD OutBufferSize,
  [out] [out]         LPDWORD BytesReturned,
  [in] [in]           PRES_CTL_CTX context,
  [in, out] [in, out] PBOOL ReturnedAsynchronously
)
{...}