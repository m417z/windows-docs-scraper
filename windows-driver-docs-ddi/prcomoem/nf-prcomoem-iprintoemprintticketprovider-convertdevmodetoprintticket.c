HRESULT ConvertDevModeToPrintTicket(
  [in]      ULONG            cbDevmode,
  [in]      PDEVMODE         pDevmode,
  [in]      ULONG            cbDrvPrivateSize,
  [in]      PVOID            pPrivateDevmode,
  [in, out] IXMLDOMDocument2 *pPrintTicket
);