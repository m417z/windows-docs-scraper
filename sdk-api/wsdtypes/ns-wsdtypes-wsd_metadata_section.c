typedef struct _WSD_METADATA_SECTION {
  const WCHAR            *Dialect;
  const WCHAR            *Identifier;
  void                   *Data;
  WSD_ENDPOINT_REFERENCE *MetadataReference;
  const WCHAR            *Location;
  WSDXML_ELEMENT         *Any;
} WSD_METADATA_SECTION;