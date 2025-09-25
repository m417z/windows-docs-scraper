typedef struct _UCMUCSI_PPM_CONFIG {
  ULONG                        Size;
  BOOLEAN                      UsbDeviceControllerEnabled;
  UCMUCSI_CONNECTOR_COLLECTION ConnectorCollectionHandle;
} UCMUCSI_PPM_CONFIG, *PUCMUCSI_PPM_CONFIG;