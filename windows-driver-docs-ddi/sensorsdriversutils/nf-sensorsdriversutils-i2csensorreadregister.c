NTSTATUS I2CSensorReadRegister(
  WDFIOTARGET I2CIoTarget,
  UCHAR       RegAddress,
  BYTE        *Buffer,
  ULONG       BufferCb
);