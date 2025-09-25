HRESULT WsGetXmlAttribute(
  [in]           WS_XML_READER       *reader,
  [in]           const WS_XML_STRING *localName,
  [in]           WS_HEAP             *heap,
                 WCHAR               **valueChars,
  [out]          ULONG               *valueCharCount,
  [in, optional] WS_ERROR            *error
);