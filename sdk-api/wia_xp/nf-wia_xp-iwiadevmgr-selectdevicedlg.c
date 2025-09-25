HRESULT SelectDeviceDlg(
  [in]          HWND     hwndParent,
  [in]          LONG     lDeviceType,
  [in]          LONG     lFlags,
  [in, out]     BSTR     *pbstrDeviceID,
  [out, retval] IWiaItem **ppItemRoot
);