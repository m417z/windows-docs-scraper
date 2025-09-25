typedef union _UCSI_MESSAGE_IN {
  UINT8                            AsBuffer[UCSI_MAX_DATA_LENGTH];
  UCSI_GET_CAPABILITY_IN           Capability;
  UCSI_GET_CONNECTOR_CAPABILITY_IN ConnectorCapability;
  UCSI_GET_ALTERNATE_MODES_IN      AlternateModes;
  UCSI_GET_CAM_SUPPORTED_IN        CamSupported;
  UCSI_GET_CURRENT_CAM_IN          CurrentCam;
  UCSI_GET_PDOS_IN                 Pdos;
  UCSI_GET_CABLE_PROPERTY_IN       CableProperty;
  UCSI_GET_CONNECTOR_STATUS_IN     ConnectorStatus;
  UCSI_GET_ERROR_STATUS_IN         ErrorStatus;
} UCSI_MESSAGE_IN, *PUCSI_MESSAGE_IN;