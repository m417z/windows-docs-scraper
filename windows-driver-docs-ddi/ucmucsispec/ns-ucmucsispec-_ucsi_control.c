typedef union _UCSI_CONTROL {
  UINT64                                AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 CommandSpecific : 48;
  };
  UCSI_CONNECTOR_RESET_COMMAND          ConnectorReset;
  UCSI_ACK_CC_CI_COMMAND                AckCcCi;
  UCSI_SET_NOTIFICATION_ENABLE_COMMAND  SetNotificationEnable;
  UCSI_GET_CONNECTOR_CAPABILITY_COMMAND GetConnectorCapability;
  UCSI_SET_UOM_COMMAND                  SetUom;
  UCSI_SET_UOR_COMMAND                  SetUor;
  UCSI_SET_PDM_COMMAND                  SetPdm;
  UCSI_SET_PDR_COMMAND                  SetPdr;
  UCSI_GET_ALTERNATE_MODES_COMMAND      GetAlternateModes;
  UCSI_GET_CAM_SUPPORTED_COMMAND        GetCamSupported;
  UCSI_GET_CURRENT_CAM_COMMAND          GetCurrentCam;
  UCSI_SET_NEW_CAM_COMMAND              SetNewCam;
  UCSI_GET_PDOS_COMMAND                 GetPdos;
  UCSI_GET_CABLE_PROPERTY_COMMAND       GetCableProperty;
  UCSI_GET_CONNECTOR_STATUS_COMMAND     GetConnectorStatus;
  UCSI_GET_ERROR_STATUS_COMMAND         GetErrorStatus;
  UCSI_SET_POWER_LEVEL_COMMAND          SetPowerLevel;
} UCSI_CONTROL, *PUCSI_CONTROL;