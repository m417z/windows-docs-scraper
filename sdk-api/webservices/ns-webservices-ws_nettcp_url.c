typedef struct _WS_NETTCP_URL {
  WS_URL    url;
  WS_STRING host;
  USHORT    port;
  WS_STRING portAsString;
  WS_STRING path;
  WS_STRING query;
  WS_STRING fragment;
} WS_NETTCP_URL;