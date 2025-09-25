typedef enum _HTTP_SERVER_PROPERTY {
  HttpServerAuthenticationProperty = 0,
  HttpServerLoggingProperty = 1,
  HttpServerQosProperty = 2,
  HttpServerTimeoutsProperty = 3,
  HttpServerQueueLengthProperty = 4,
  HttpServerStateProperty = 5,
  HttpServer503VerbosityProperty = 6,
  HttpServerBindingProperty = 7,
  HttpServerExtendedAuthenticationProperty = 8,
  HttpServerListenEndpointProperty = 9,
  HttpServerChannelBindProperty = 10,
  HttpServerProtectionLevelProperty = 11,
  HttpServerDelegationProperty,
  HttpServerFastForwardingProperty
} HTTP_SERVER_PROPERTY, *PHTTP_SERVER_PROPERTY;