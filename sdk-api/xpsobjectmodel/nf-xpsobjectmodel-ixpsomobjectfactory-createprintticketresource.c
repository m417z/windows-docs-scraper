HRESULT CreatePrintTicketResource(
  [in]          IStream                   *acquiredStream,
  [in]          IOpcPartUri               *partUri,
  [out, retval] IXpsOMPrintTicketResource **printTicketResource
);