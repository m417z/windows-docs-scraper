DRMEXPORT HRESULT UDAPICALL DRMGetServiceLocation(
  [in, optional] DRMHSESSION hClient,
  [in]           UINT        uServiceType,
  [in]           UINT        uServiceLocation,
  [in]           PWSTR       wszIssuanceLicense,
  [in, out]      UINT        *puServiceURLLength,
  [out]          PWSTR       wszServiceURL
);