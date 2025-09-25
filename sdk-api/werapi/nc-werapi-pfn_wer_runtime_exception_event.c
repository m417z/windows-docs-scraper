PFN_WER_RUNTIME_EXCEPTION_EVENT PfnWerRuntimeExceptionEvent;

HRESULT PfnWerRuntimeExceptionEvent(
  [in]      PVOID pContext,
  [in]      const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation,
  [out]     BOOL *pbOwnershipClaimed,
  [out]     PWSTR pwszEventName,
  [in, out] PDWORD pchSize,
  [out]     PDWORD pdwSignatureCount
)
{...}