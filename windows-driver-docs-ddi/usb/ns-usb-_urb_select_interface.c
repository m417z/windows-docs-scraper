struct _URB_SELECT_INTERFACE {
  struct _URB_HEADER         Hdr;
  USBD_CONFIGURATION_HANDLE  ConfigurationHandle;
  USBD_INTERFACE_INFORMATION Interface;
};