HRESULT CreatePackageWriterOnStream(
  [in]          ISequentialStream         *outputStream,
  [in]          BOOL                      optimizeMarkupSize,
  [in]          XPS_INTERLEAVING          interleaving,
  [in]          IOpcPartUri               *documentSequencePartName,
  [in]          IXpsOMCoreProperties      *coreProperties,
  [in]          IXpsOMImageResource       *packageThumbnail,
  [in]          IXpsOMPrintTicketResource *documentSequencePrintTicket,
  [in]          IOpcPartUri               *discardControlPartName,
  [out, retval] IXpsOMPackageWriter       **packageWriter
);