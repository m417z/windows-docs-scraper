HRESULT PTMergeAndValidatePrintTicket(
  [in]  HPTPROVIDER       hProvider,
  [in]  IStream           *pBaseTicket,
  [in]  IStream           *pDeltaTicket,
  [in]  EPrintTicketScope scope,
        IStream           *pResultTicket,
  [out] BSTR              *pbstrErrorMessage
);