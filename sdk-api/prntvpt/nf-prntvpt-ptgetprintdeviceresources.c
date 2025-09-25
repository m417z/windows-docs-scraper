HRESULT PTGetPrintDeviceResources(
  [in]            HPTPROVIDER hProvider,
  [in]            LPCWSTR     pszLocaleName,
  [in]            IStream     *pPrintTicket,
                  IStream     *pDeviceResources,
  [out, optional] BSTR        *pbstrErrorMessage
);