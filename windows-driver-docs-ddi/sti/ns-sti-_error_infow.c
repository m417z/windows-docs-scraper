typedef struct _ERROR_INFOW {
  DWORD dwSize;
  DWORD dwGenericError;
  DWORD dwVendorError;
  WCHAR szExtendedErrorText[255];
} STI_ERROR_INFOW, *PSTI_ERROR_INFOW;