typedef struct _WSD_RESOLVE_MATCH {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSD_NAME_LIST          *Types;
  WSD_SCOPES             *Scopes;
  WSD_URI_LIST           *XAddrs;
  ULONGLONG              MetadataVersion;
  WSDXML_ELEMENT         *Any;
} WSD_RESOLVE_MATCH;