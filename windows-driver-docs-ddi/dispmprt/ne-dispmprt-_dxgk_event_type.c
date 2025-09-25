typedef enum _DXGK_EVENT_TYPE {
  DxgkUndefinedEvent,
  DxgkAcpiEvent,
  DxgkPowerStateEvent,
  DxgkDockingEvent,
  DxgkChainedAcpiEvent
} DXGK_EVENT_TYPE, *PDXGK_EVENT_TYPE;