HRESULT AddPage(
  [in]            ID2D1CommandList *commandList,
                  D2D_SIZE_F       pageSize,
  [in, optional]  IStream          *pagePrintTicketStream,
  [out, optional] D2D1_TAG         *tag1,
  [out, optional] D2D1_TAG         *tag2
);