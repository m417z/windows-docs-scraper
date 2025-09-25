struct _URB_HEADER {
  USHORT      Length;
  USHORT      Function;
  USBD_STATUS Status;
  PVOID       UsbdDeviceHandle;
  ULONG       UsbdFlags;
};