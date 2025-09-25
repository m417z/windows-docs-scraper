WS_WRITE_TYPE_CALLBACK WsWriteTypeCallback;

HRESULT WsWriteTypeCallback(
  [in]           WS_XML_WRITER *writer,
  [in]           WS_TYPE_MAPPING typeMapping,
  [in]           const void *descriptionData,
                 const void *value,
  [in]           ULONG valueSize,
  [in, optional] WS_ERROR *error
)
{...}