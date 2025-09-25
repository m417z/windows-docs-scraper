typedef struct _WSD_SERVICE_METADATA {
  WSD_ENDPOINT_REFERENCE_LIST *EndpointReference;
  WSD_NAME_LIST               *Types;
  const WCHAR                 *ServiceId;
  WSDXML_ELEMENT              *Any;
} WSD_SERVICE_METADATA;