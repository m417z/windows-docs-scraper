HRESULT FormatRequestForRead(
  [in]           IWDFIoRequest     *pRequest,
  [in, optional] IWDFFile          *pFile,
  [in, optional] IWDFMemory        *pOutputMemory,
  [in, optional] PWDFMEMORY_OFFSET pOutputMemoryOffset,
  [in, optional] PLONGLONG         DeviceOffset
);