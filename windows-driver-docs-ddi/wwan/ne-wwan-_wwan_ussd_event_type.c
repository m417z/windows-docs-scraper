typedef enum _WWAN_USSD_EVENT_TYPE {
  WwanUssdEventNoActionRequired,
  WwanUssdEventActionRequired,
  WwanUssdEventTerminated,
  WwanUssdEventOtherLocalClient,
  WwanUssdEventOperationNotSupported,
  WwanUssdEventNetworkTimeOut
} WWAN_USSD_EVENT_TYPE, *PWWAN_USSD_EVENT_TYPE;