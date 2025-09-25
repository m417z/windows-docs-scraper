PFN_WdsCliCallback PfnWdsclicallback;

VOID PfnWdsclicallback(
  [in]           DWORD dwMessageId,
  [in, optional] WPARAM wParam,
  [in, optional] LPARAM lParam,
  [in, optional] PVOID pvUserData
)
{...}