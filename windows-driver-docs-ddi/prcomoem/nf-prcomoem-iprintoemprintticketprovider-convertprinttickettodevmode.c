HRESULT ConvertPrintTicketToDevMode(
  [in]      IXMLDOMDocument2 *pPrintTicket,
  [in]      ULONG            cbDevmode,
  [in, out] PDEVMODE         pDevmode,
  [in]      ULONG            cbDrvPrivateSize,
  [in]      PVOID            pPrivateDevmode
);