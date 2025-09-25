HRESULT PTGetPrintDeviceCapabilities(
  [in]            HPTPROVIDER hProvider,
  [in, optional]  IStream     *pPrintTicket,
                  IStream     *pDeviceCapabilities,
  [out, optional] BSTR        *pbstrErrorMessage
);