typedef struct _USB_BUS_INTERFACE_USBDI_V3 {
  USHORT                             Size;
  USHORT                             Version;
  PVOID                              BusContext;
  PINTERFACE_REFERENCE               InterfaceReference;
  PINTERFACE_DEREFERENCE             InterfaceDereference;
  PUSB_BUSIFFN_GETUSBDI_VERSION      GetUSBDIVersion;
  PUSB_BUSIFFN_QUERY_BUS_TIME        QueryBusTime;
  PUSB_BUSIFFN_SUBMIT_ISO_OUT_URB    SubmitIsoOutUrb;
  PUSB_BUSIFFN_QUERY_BUS_INFORMATION QueryBusInformation;
  PUSB_BUSIFFN_IS_DEVICE_HIGH_SPEED  IsDeviceHighSpeed;
  PUSB_BUSIFFN_ENUM_LOG_ENTRY        EnumLogEntry;
  PUSB_BUSIFFN_QUERY_BUS_TIME_EX     QueryBusTimeEx;
  PUSB_BUSIFFN_QUERY_CONTROLLER_TYPE QueryControllerType;
} USB_BUS_INTERFACE_USBDI_V3, *PUSB_BUS_INTERFACE_USBDI_V3;