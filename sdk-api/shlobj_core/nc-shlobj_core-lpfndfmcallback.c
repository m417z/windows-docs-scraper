LPFNDFMCALLBACK Lpfndfmcallback;

HRESULT Lpfndfmcallback(
  [in, optional] IShellFolder *psf,
  [in, optional] HWND hwnd,
  [in, optional] IDataObject *pdtobj,
                 UINT uMsg,
                 WPARAM wParam,
                 LPARAM lParam
)
{...}