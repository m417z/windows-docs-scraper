CBADMITRESULT Cbadmitresult;

ULONG * Cbadmitresult(
  [in] LPM_HANDLE LpmHandle,
  [in] RHANDLE RequestHandle,
  [in] ULONG ulPcmActionFlags,
  [in] int LpmError,
  [in] int PolicyDecisionsCount,
  [in] POLICY_DECISION *pPolicyDecisions
)
{...}