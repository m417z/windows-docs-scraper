typedef struct _USBPM_CONNECTOR_PROPERTIES {
  USBPM_CONNECTOR ConnectorHandle;
  USBPM_HUB       ParentHubHandle;
  ULONG64         ConnectorId;
  ULONG           SupportedTypeCOperatingModes;
  ULONG           SupportedTypeCSourceCurrentAdvertisements;
  BOOLEAN         IsTypeCAudioAccessorySupported;
  BOOLEAN         IsPdSupported;
  ULONG           SupportedPowerRoles;
} USBPM_CONNECTOR_PROPERTIES, *PUSBPM_CONNECTOR_PROPERTIES;