typedef struct _UCM_CONNECTOR_CONFIG {
  ULONG                       Size;
  ULONGLONG                   ConnectorId;
  PUCM_CONNECTOR_TYPEC_CONFIG TypeCConfig;
  PUCM_CONNECTOR_PD_CONFIG    PdConfig;
} UCM_CONNECTOR_CONFIG, *PUCM_CONNECTOR_CONFIG;