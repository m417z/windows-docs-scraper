PFAX_SEND_CALLBACK PfaxSendCallback;

BOOL PfaxSendCallback(
  [in] HANDLE FaxHandle,
  [in] HCALL CallHandle,
  [in] DWORD Reserved1,
  [in] DWORD Reserved2
)
{...}