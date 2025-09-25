HRESULT PTConvertPrintTicketToDevMode(
  [in]  HPTPROVIDER         hProvider,
  [in]  IStream             *pPrintTicket,
        EDefaultDevmodeType baseDevmodeType,
  [in]  EPrintTicketScope   scope,
  [out] ULONG               *pcbDevmode,
  [out] PDEVMODE            *ppDevmode,
  [out] BSTR                *pbstrErrorMessage
);