typedef struct _HTTP_REQUEST_V2 : _HTTP_REQUEST_V1 {
  USHORT             RequestInfoCount;
  PHTTP_REQUEST_INFO pRequestInfo;
} HTTP_REQUEST_V2, *PHTTP_REQUEST_V2;