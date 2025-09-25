PFN_WER_RUNTIME_EXCEPTION_EVENT_SIGNATURE PfnWerRuntimeExceptionEventSignature;

HRESULT PfnWerRuntimeExceptionEventSignature(
  [in]      PVOID pContext,
  [in]      const PWER_RUNTIME_EXCEPTION_INFORMATION pExceptionInformation,
  [in]      DWORD dwIndex,
  [out]     PWSTR pwszName,
  [in, out] PDWORD pchName,
  [out]     PWSTR pwszValue,
  [in, out] PDWORD pchValue
)
{...}