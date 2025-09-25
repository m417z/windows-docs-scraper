WS_READ_TYPE_CALLBACK WsReadTypeCallback;

HRESULT WsReadTypeCallback(
  [in]           WS_XML_READER *reader,
  [in]           WS_TYPE_MAPPING typeMapping,
  [in]           const void *descriptionData,
  [in, optional] WS_HEAP *heap,
                 void *value,
  [in]           ULONG valueSize,
  [in, optional] WS_ERROR *error
)
{...}