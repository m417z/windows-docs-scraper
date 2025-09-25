HRESULT FormatRequestForWrite(
  [in]           IWDFIoRequest     *pRequest,
  [in, optional] IWDFFile          *pFile,
  [in, optional] IWDFMemory        *pInputMemory,
  [in, optional] PWDFMEMORY_OFFSET pInputMemoryOffset,
  [in, optional] PLONGLONG         DeviceOffset
);