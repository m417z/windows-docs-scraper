HRESULT PTGetPrintCapabilities(
  [in]  HPTPROVIDER hProvider,
  [in]  IStream     *pPrintTicket,
        IStream     *pCapabilities,
  [out] BSTR        *pbstrErrorMessage
);