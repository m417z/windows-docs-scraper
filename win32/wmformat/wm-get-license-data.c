typedef struct _WMGetLicenseData {
  DWORD   dwSize;
  HRESULT hr;
  WCHAR   *wszURL;
  WCHAR   *wszLocalFilename;
  BYTE    *pbPostData;
  DWORD   dwPostDataSize;
} WM_GET_LICENSE_DATA;