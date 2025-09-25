HRESULT WsReadBytes(
  [in]           WS_XML_READER *reader,
                 void          *bytes,
  [in]           ULONG         maxByteCount,
  [out]          ULONG         *actualByteCount,
  [in, optional] WS_ERROR      *error
);