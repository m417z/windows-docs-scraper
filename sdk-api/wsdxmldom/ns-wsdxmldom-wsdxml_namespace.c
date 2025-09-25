typedef struct _WSDXML_NAMESPACE {
  const WCHAR *Uri;
  const WCHAR *PreferredPrefix;
  WSDXML_NAME *Names;
  WORD        NamesCount;
  WORD        Encoding;
} WSDXML_NAMESPACE;