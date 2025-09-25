struct _BRB_GET_DEVICE_INTERFACE_STRING {
  BRB_HEADER Hdr;
  PWCHAR     DeviceInterfaceString;
  ULONG      DeviceInterfaceStringCbLength;
};