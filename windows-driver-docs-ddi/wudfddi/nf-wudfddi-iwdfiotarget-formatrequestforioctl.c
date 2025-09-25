HRESULT FormatRequestForIoctl(
  [in]           IWDFIoRequest     *pRequest,
  [in]           ULONG             IoctlCode,
  [in, optional] IWDFFile          *pFile,
  [in, optional] IWDFMemory        *pInputMemory,
  [in, optional] PWDFMEMORY_OFFSET pInputMemoryOffset,
  [in, optional] IWDFMemory        *pOutputMemory,
  [in, optional] PWDFMEMORY_OFFSET pOutputMemoryOffset
);