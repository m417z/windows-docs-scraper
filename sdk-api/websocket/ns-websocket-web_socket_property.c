typedef struct _WEB_SOCKET_PROPERTY {
  WEB_SOCKET_PROPERTY_TYPE Type;
  PVOID                    pvValue;
  ULONG                    ulValueSize;
} WEB_SOCKET_PROPERTY, *PWEB_SOCKET_PROPERTY;