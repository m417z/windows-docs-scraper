typedef struct _USBPM_CONNECTOR_STATE {
  USBPM_CONNECTOR             ConnectorHandle;
  ULONG                       ChangeToken;
  BOOLEAN                     Attached;
  ULONG                       AttachCount;
  USBC_PARTNER                Partner;
  USBC_CURRENT                CurrentAdvertisement;
  USBC_PD_CONN_STATE          PdConnState;
  USBC_PD_REQUEST_DATA_OBJECT Rdo;
  USBC_DATA_ROLE              DataRole;
  USBC_POWER_ROLE             PowerRole;
  UINT8                       SourceCapsCount;
  USBC_PD_POWER_DATA_OBJECT   SourceCaps[USBPM_MAX_CAPS_COUNT];
  UINT8                       SinkCapsCount;
  USBC_PD_POWER_DATA_OBJECT   SinkCaps[USBPM_MAX_CAPS_COUNT];
  UINT8                       PartnerSourceCapsCount;
  USBC_PD_POWER_DATA_OBJECT   PartnerSourceCaps[USBPM_MAX_CAPS_COUNT];
  ULONG                       PdAlternateModesEnteredCount;
} USBPM_CONNECTOR_STATE, *PUSBPM_CONNECTOR_STATE;