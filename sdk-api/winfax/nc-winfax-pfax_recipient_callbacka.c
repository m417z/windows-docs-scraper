PFAX_RECIPIENT_CALLBACKA PfaxRecipientCallbacka;

BOOL PfaxRecipientCallbacka(
  [in]                HANDLE FaxHandle,
  [in]                DWORD RecipientNumber,
  [in]                LPVOID Context,
  [in, out]           PFAX_JOB_PARAMA JobParams,
  [in, out, optional] PFAX_COVERPAGE_INFOA CoverpageInfo
)
{...}