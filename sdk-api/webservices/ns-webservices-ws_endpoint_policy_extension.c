typedef struct _WS_ENDPOINT_POLICY_EXTENSION {
  WS_POLICY_EXTENSION policyExtension;
  WS_XML_STRING       *assertionName;
  WS_XML_STRING       *assertionNs;
  struct {
    WS_XML_BUFFER *assertionValue;
  } out;
} WS_ENDPOINT_POLICY_EXTENSION;