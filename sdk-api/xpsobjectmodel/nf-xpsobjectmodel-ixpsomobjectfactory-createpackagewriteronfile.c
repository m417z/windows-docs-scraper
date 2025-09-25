HRESULT CreatePackageWriterOnFile(
  [in]          LPCWSTR                   fileName,
  [in]          LPSECURITY_ATTRIBUTES     securityAttributes,
  [in]          DWORD                     flagsAndAttributes,
  [in]          BOOL                      optimizeMarkupSize,
  [in]          XPS_INTERLEAVING          interleaving,
  [in]          IOpcPartUri               *documentSequencePartName,
  [in]          IXpsOMCoreProperties      *coreProperties,
  [in]          IXpsOMImageResource       *packageThumbnail,
  [in]          IXpsOMPrintTicketResource *documentSequencePrintTicket,
  [in]          IOpcPartUri               *discardControlPartName,
  [out, retval] IXpsOMPackageWriter       **packageWriter
);