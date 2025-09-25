typedef struct _HTTP_REQUEST_INFO {
  HTTP_REQUEST_INFO_TYPE InfoType;
  ULONG                  InfoLength;
  PVOID                  pInfo;
} HTTP_REQUEST_INFO, *PHTTP_REQUEST_INFO;