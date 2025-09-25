PBEGIN_RESTYPECALL_AS_USER_ROUTINE PbeginRestypecallAsUserRoutine;

DWORD PbeginRestypecallAsUserRoutine(
  [in] [in]           LPCWSTR ResourceTypeName,
  [in] [in]           HANDLE TokenHandle,
  [in] [in]           DWORD ControlCode,
  [in] [in]           PVOID InBuffer,
  [in] [in]           DWORD InBufferSize,
  [out] [out]         PVOID OutBuffer,
  [in] [in]           DWORD OutBufferSize,
  [out] [out]         LPDWORD BytesReturned,
  [in] [in]           PRESTYPE_CTL_CTX context,
  [in, out] [in, out] PBOOL ReturnedAsynchronously
)
{...}