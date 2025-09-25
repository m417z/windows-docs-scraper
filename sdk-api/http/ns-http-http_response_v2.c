typedef struct _HTTP_RESPONSE_V2 : _HTTP_RESPONSE_V1 {
  USHORT              ResponseInfoCount;
  PHTTP_RESPONSE_INFO pResponseInfo;
} HTTP_RESPONSE_V2, *PHTTP_RESPONSE_V2;