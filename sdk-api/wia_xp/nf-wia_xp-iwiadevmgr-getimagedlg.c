HRESULT GetImageDlg(
  [in]      HWND     hwndParent,
  [in]      LONG     lDeviceType,
  [in]      LONG     lFlags,
  [in]      LONG     lIntent,
  [in]      IWiaItem *pItemRoot,
  [in]      BSTR     bstrFilename,
  [in, out] GUID     *pguidFormat
);