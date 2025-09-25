typedef struct {
  WSD_ENDPOINT_REFERENCE *SubscriptionManager;
  const WCHAR            *Status;
  WSD_LOCALIZED_STRING   *Reason;
  WSDXML_ELEMENT         *Any;
} RESPONSEBODY_SubscriptionEnd;