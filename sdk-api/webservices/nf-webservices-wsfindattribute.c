HRESULT WsFindAttribute(
  [in]           WS_XML_READER       *reader,
  [in]           const WS_XML_STRING *localName,
  [in]           const WS_XML_STRING *ns,
  [in]           BOOL                required,
  [out]          ULONG               *attributeIndex,
  [in, optional] WS_ERROR            *error
);