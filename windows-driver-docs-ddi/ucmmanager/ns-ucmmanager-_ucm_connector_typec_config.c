typedef struct _UCM_CONNECTOR_TYPEC_CONFIG {
  ULONG                           Size;
  BOOLEAN                         IsSupported;
  ULONG                           SupportedOperatingModes;
  ULONG                           SupportedPowerSourcingCapabilities;
  BOOLEAN                         AudioAccessoryCapable;
  PFN_UCM_CONNECTOR_SET_DATA_ROLE EvtSetDataRole;
} UCM_CONNECTOR_TYPEC_CONFIG, *PUCM_CONNECTOR_TYPEC_CONFIG;