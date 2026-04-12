struct IDARG_IN_I2C_TRANSMIT_AND_RECEIVE {
  UINT  TransmitSevenBitI2CAddress;
  UINT  TransmitDataSizeInBytes;
  PVOID pTransmitData;
  UINT  ReceiveSevenBitI2CAddress;
  UINT  ReceiveFlags;
  UINT  ReceiveDataSizeInBytes;
  PVOID pReceiveData;
};