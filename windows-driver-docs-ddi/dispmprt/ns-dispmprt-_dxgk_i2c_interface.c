typedef struct _DXGK_I2C_INTERFACE {
  USHORT                                Size;
  USHORT                                Version;
  PVOID                                 Context;
  PINTERFACE_REFERENCE                  InterfaceReference;
  PINTERFACE_DEREFERENCE                InterfaceDereference;
  DXGKDDI_I2C_TRANSMIT_DATA_TO_DISPLAY  DxgkDdiI2CTransmitDataToDisplay;
  DXGKDDI_I2C_RECEIVE_DATA_FROM_DISPLAY DxgkDdiI2CReceiveDataFromDisplay;
} DXGK_I2C_INTERFACE, *PDXGK_I2C_INTERFACE;