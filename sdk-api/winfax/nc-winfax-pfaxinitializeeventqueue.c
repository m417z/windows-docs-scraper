PFAXINITIALIZEEVENTQUEUE Pfaxinitializeeventqueue;

BOOL Pfaxinitializeeventqueue(
  [in] HANDLE FaxHandle,
  [in] HANDLE CompletionPort,
  [in] ULONG_PTR CompletionKey,
  [in] HWND hWnd,
  [in] UINT MessageStart
)
{...}