WINEVENTPROC Wineventproc;

VOID Wineventproc(
  HWINEVENTHOOK hWinEventHook,
  DWORD event,
  HWND hwnd,
  LONG idObject,
  LONG idChild,
  DWORD idEventThread,
  DWORD dwmsEventTime
)
{...}