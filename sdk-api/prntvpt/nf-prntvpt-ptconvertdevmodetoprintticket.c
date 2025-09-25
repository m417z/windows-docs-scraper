HRESULT PTConvertDevModeToPrintTicket(
  [in] HPTPROVIDER       hProvider,
       ULONG             cbDevmode,
  [in] PDEVMODE          pDevmode,
  [in] EPrintTicketScope scope,
       IStream           *pPrintTicket
);