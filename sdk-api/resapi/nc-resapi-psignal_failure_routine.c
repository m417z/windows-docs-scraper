PSIGNAL_FAILURE_ROUTINE PsignalFailureRoutine;

DWORD PsignalFailureRoutine(
  [in] RESOURCE_HANDLE ResourceHandle,
  [in] FAILURE_TYPE FailureType,
  [in] DWORD ApplicationSpecificErrorCode
)
{...}