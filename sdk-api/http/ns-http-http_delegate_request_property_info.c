typedef struct _HTTP_DELEGATE_REQUEST_PROPERTY_INFO {
  HTTP_DELEGATE_REQUEST_PROPERTY_ID PropertyId;
  ULONG                             PropertyInfoLength;
  PVOID                             PropertyInfo;
} HTTP_DELEGATE_REQUEST_PROPERTY_INFO, *PHTTP_DELEGATE_REQUEST_PROPERTY_INFO;