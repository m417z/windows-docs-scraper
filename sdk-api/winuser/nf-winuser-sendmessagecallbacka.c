BOOL SendMessageCallbackA(
  [in] HWND          hWnd,
  [in] UINT          Msg,
  [in] WPARAM        wParam,
  [in] LPARAM        lParam,
  [in] SENDASYNCPROC lpResultCallBack,
  [in] ULONG_PTR     dwData
);