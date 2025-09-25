HRESULT WsReadArray(
  [in]           WS_XML_READER       *reader,
  [in]           const WS_XML_STRING *localName,
  [in]           const WS_XML_STRING *ns,
  [in]           WS_VALUE_TYPE       valueType,
                 void                *array,
  [in]           ULONG               arraySize,
  [in]           ULONG               itemOffset,
  [in]           ULONG               itemCount,
  [out]          ULONG               *actualItemCount,
  [in, optional] WS_ERROR            *error
);