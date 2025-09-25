typedef struct _USBPM_EVENT_CALLBACK_PARAMS {
  USBPM_EVENT_TYPE EventType;
  union {
    struct {
      ULONG AccessGranted;
    } PolicyManagerArrival;
    struct {
      USBPM_HUB HubHandle;
    } HubArrivalRemoval;
    struct {
      USBPM_CONNECTOR ConnectorHandle;
    } ConnectorStateChange;
  } EventData;
  PVOID            Context;
} USBPM_EVENT_CALLBACK_PARAMS, *PUSBPM_EVENT_CALLBACK_PARAMS;