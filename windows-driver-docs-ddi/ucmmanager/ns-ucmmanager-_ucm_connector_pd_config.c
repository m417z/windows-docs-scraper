typedef struct _UCM_CONNECTOR_PD_CONFIG {
  ULONG                            Size;
  BOOLEAN                          IsSupported;
  ULONG                            SupportedPowerRoles;
  PFN_UCM_CONNECTOR_SET_POWER_ROLE EvtSetPowerRole;
} UCM_CONNECTOR_PD_CONFIG, *PUCM_CONNECTOR_PD_CONFIG;