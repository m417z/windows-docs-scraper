typedef enum _HTTP_RESPONSE_INFO_TYPE {
  HttpResponseInfoTypeMultipleKnownHeaders,
  HttpResponseInfoTypeAuthenticationProperty,
  HttpResponseInfoTypeQoSProperty,
  HttpResponseInfoTypeChannelBind
} HTTP_RESPONSE_INFO_TYPE, *PHTTP_RESPONSE_INFO_TYPE;