typedef struct _WSD_PROBE_MATCH {
  WSD_ENDPOINT_REFERENCE *EndpointReference;
  WSD_NAME_LIST          *Types;
  WSD_SCOPES             *Scopes;
  WSD_URI_LIST           *XAddrs;
  ULONGLONG              MetadataVersion;
  WSDXML_ELEMENT         *Any;
} WSD_PROBE_MATCH;