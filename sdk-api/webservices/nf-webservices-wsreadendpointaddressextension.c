HRESULT WsReadEndpointAddressExtension(
  [in]           WS_XML_READER                      *reader,
  [in]           WS_ENDPOINT_ADDRESS                *endpointAddress,
  [in]           WS_ENDPOINT_ADDRESS_EXTENSION_TYPE extensionType,
  [in]           WS_READ_OPTION                     readOption,
  [in]           WS_HEAP                            *heap,
                 void                               *value,
  [in]           ULONG                              valueSize,
  [in, optional] WS_ERROR                           *error
);