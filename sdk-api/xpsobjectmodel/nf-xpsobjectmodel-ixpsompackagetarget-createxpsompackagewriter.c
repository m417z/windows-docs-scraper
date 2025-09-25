HRESULT CreateXpsOMPackageWriter(
  [in]           IOpcPartUri               *documentSequencePartName,
  [in, optional] IXpsOMPrintTicketResource *documentSequencePrintTicket,
  [in, optional] IOpcPartUri               *discardControlPartName,
  [out, retval]  IXpsOMPackageWriter       **packageWriter
);