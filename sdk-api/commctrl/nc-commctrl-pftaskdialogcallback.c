PFTASKDIALOGCALLBACK Pftaskdialogcallback;

HRESULT Pftaskdialogcallback(
  [in] HWND hwnd,
  [in] UINT msg,
  [in] WPARAM wParam,
  [in] LPARAM lParam,
       LONG_PTR lpRefData
)
{...}