HRESULT CreatePackageWriterOnStream1(
  ISequentialStream         *outputStream,
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