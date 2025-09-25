HTTPAPI_LINKAGE ULONG HttpDelegateRequestEx(
  HANDLE                               RequestQueueHandle,
  HANDLE                               DelegateQueueHandle,
  HTTP_REQUEST_ID                      RequestId,
  HTTP_URL_GROUP_ID                    DelegateUrlGroupId,
  ULONG                                PropertyInfoSetSize,
  PHTTP_DELEGATE_REQUEST_PROPERTY_INFO PropertyInfoSet
);