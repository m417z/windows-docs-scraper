HRESULT WsCreateMessage(
  [in]           WS_ENVELOPE_VERSION       envelopeVersion,
  [in]           WS_ADDRESSING_VERSION     addressingVersion,
                 const WS_MESSAGE_PROPERTY *properties,
  [in]           ULONG                     propertyCount,
                 WS_MESSAGE                **message,
  [in, optional] WS_ERROR                  *error
);