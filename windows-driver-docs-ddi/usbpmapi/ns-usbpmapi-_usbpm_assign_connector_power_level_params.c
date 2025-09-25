typedef struct _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS {
  USBC_POWER_ROLE                        PowerRole;
  USBPM_ASSIGN_POWER_LEVEL_PARAMS_FORMAT Format;
  union {
    struct {
      UINT8                               MaximumPdPowerIn500mW;
      USBC_UCSI_SET_POWER_LEVEL_C_CURRENT MaximumTypeCCurrent;
    } Ucsi;
    struct {
      USBC_PD_REQUEST_DATA_OBJECT Rdo;
    } Rdo;
  };
} USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS, *PUSBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS;