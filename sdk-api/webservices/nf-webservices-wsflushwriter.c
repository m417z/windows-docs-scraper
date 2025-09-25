HRESULT WsFlushWriter(
  [in]           WS_XML_WRITER          *writer,
  [in]           ULONG                  minSize,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR               *error
);