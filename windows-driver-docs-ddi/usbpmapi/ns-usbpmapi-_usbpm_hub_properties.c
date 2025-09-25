typedef struct _USBPM_HUB_PROPERTIES {
  USBPM_HUB ParentHubHandle;
  USBPM_HUB HubHandle;
  ULONG     ConnectorCount;
} USBPM_HUB_PROPERTIES, *PUSBPM_HUB_PROPERTIES;