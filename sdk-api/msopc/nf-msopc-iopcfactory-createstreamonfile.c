HRESULT CreateStreamOnFile(
  [in]          LPCWSTR               filename,
  [in]          OPC_STREAM_IO_MODE    ioMode,
  [in]          LPSECURITY_ATTRIBUTES securityAttributes,
  [in]          DWORD                 dwFlagsAndAttributes,
  [out, retval] IStream               **stream
);