UINT_PTR SetCoalescableTimer(
  [in, optional] HWND      hWnd,
  [in]           UINT_PTR  nIDEvent,
  [in]           UINT      uElapse,
  [in, optional] TIMERPROC lpTimerFunc,
  [in]           ULONG     uToleranceDelay
);