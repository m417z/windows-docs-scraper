typedef enum _WDF_PNP_STATE {
  WdfPnpStateInvalid,
  WdfPnpStateDisabled,
  WdfPnpStateFailed,
  WdfPnpStateRemoved,
  WdfPnpStateResourcesChanged,
  WdfPnpStateDontDisplayInUI,
  WdfPnpStateNotDisableable,
  WdfPnpStateMaximum
} WDF_PNP_STATE;