struct IDARG_IN_I2C_RECEIVE {
  [in]  UINT  SevenBitI2CAddress;
  [in]  UINT  Flags;
  [in]  UINT  DataSizeInBytes;
  [out] PVOID pData;
};