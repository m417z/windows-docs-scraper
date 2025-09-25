BOOL ChangeWindowMessageFilterEx(
  [in]                HWND                hwnd,
  [in]                UINT                message,
  [in]                DWORD               action,
  [in, out, optional] PCHANGEFILTERSTRUCT pChangeFilterStruct
);