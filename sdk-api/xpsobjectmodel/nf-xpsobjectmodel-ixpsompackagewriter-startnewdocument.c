HRESULT StartNewDocument(
  [in] IOpcPartUri                            *documentPartName,
  [in] IXpsOMPrintTicketResource              *documentPrintTicket,
  [in] IXpsOMDocumentStructureResource        *documentStructure,
  [in] IXpsOMSignatureBlockResourceCollection *signatureBlockResources,
  [in] IXpsOMPartUriCollection                *restrictedFonts
);