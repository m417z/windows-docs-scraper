HRESULT ConvertPrintTicketToDevMode(
  [in]  IN IXMLDOMDocument2 *pPrintTicket,
  [in]  IN ULONG            cbDevmodeIn,
  [in]  IN PDEVMODE         pDevmodeIn,
  [out] OUT ULONG           *pcbDevmodeOut,
  [out] OUT PDEVMODE        *ppDevmodeOut
);