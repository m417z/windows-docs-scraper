NTSTATUS I2CSensorWriteRegister(
  WDFIOTARGET I2CIoTarget,
  UCHAR       RegAddress,
  BYTE        *RegValue,
  size_t      RegLength
);