LPFNVIEWCALLBACK Lpfnviewcallback;

HRESULT Lpfnviewcallback(
  [in] IShellView *psvOuter,
  [in] IShellFolder *psf,
  [in] HWND hwndMain,
       UINT uMsg,
       WPARAM wParam,
       LPARAM lParam
)
{...}