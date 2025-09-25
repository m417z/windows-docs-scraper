HRESULT CreatePackageWriterOnFile1(
  LPCWSTR                   fileName,
  LPSECURITY_ATTRIBUTES     securityAttributes,
  DWORD                     flagsAndAttributes,
  BOOL                      optimizeMarkupSize,
  XPS_INTERLEAVING          interleaving,
  IOpcPartUri               *documentSequencePartName,
  IXpsOMCoreProperties      *coreProperties,
  IXpsOMImageResource       *packageThumbnail,
  IXpsOMPrintTicketResource *documentSequencePrintTicket,
  IOpcPartUri               *discardControlPartName,
  XPS_DOCUMENT_TYPE         documentType,
  IXpsOMPackageWriter       **packageWriter
);