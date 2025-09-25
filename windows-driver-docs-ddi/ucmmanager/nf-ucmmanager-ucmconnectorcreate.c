NTSTATUS UcmConnectorCreate(
  [in]  WDFDEVICE              WdfDevice,
  [in]  PUCM_CONNECTOR_CONFIG  Config,
  [in]  PWDF_OBJECT_ATTRIBUTES Attributes,
  [out] UCMCONNECTOR           *Connector
);