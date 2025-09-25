HRESULT WsReadCharsUtf8(
  [in]           WS_XML_READER *reader,
                 BYTE          *bytes,
  [in]           ULONG         maxByteCount,
  [out]          ULONG         *actualByteCount,
  [in, optional] WS_ERROR      *error
);