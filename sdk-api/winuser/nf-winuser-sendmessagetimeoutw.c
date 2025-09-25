LRESULT SendMessageTimeoutW(
  [in]            HWND       hWnd,
  [in]            UINT       Msg,
  [in]            WPARAM     wParam,
  [in]            LPARAM     lParam,
  [in]            UINT       fuFlags,
  [in]            UINT       uTimeout,
  [out, optional] PDWORD_PTR lpdwResult
);