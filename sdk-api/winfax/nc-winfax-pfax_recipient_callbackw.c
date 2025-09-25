PFAX_RECIPIENT_CALLBACKW PfaxRecipientCallbackw;

BOOL PfaxRecipientCallbackw(
  [in]                HANDLE FaxHandle,
  [in]                DWORD RecipientNumber,
  [in]                LPVOID Context,
  [in, out]           PFAX_JOB_PARAMW JobParams,
  [in, out, optional] PFAX_COVERPAGE_INFOW CoverpageInfo
)
{...}