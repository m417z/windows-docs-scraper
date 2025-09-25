typedef struct _NDIS_WDI_INIT_PARAMETERS {
  NDIS_OBJECT_HEADER                          Header;
  ULONG                                       WdiVersion;
  NDIS_WDI_OPEN_ADAPTER_COMPLETE_HANDLER      OpenAdapterCompleteHandler;
  NDIS_WDI_CLOSE_ADAPTER_COMPLETE_HANDLER     CloseAdapterCompleteHandler;
  NDIS_WDI_IDLE_NOTIFICATION_CONFIRM_HANDLER  UeIdleNotificationConfirm;
  NDIS_WDI_IDLE_NOTIFICATION_COMPLETE_HANDLER UeIdleNotificationComplete;
} NDIS_WDI_INIT_PARAMETERS, *PNDIS_WDI_INIT_PARAMETERS;