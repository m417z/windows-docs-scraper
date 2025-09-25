HRESULT WsReadChars(
  [in]           WS_XML_READER *reader,
                 WCHAR         *chars,
  [in]           ULONG         maxCharCount,
  [out]          ULONG         *actualCharCount,
  [in, optional] WS_ERROR      *error
);