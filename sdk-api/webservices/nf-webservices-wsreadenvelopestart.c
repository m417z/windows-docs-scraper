HRESULT WsReadEnvelopeStart(
  [in]           WS_MESSAGE               *message,
  [in]           WS_XML_READER            *reader,
  [in, optional] WS_MESSAGE_DONE_CALLBACK doneCallback,
  [in, optional] void                     *doneCallbackState,
  [in, optional] WS_ERROR                 *error
);