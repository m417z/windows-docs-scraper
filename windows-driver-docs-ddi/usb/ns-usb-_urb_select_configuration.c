struct _URB_SELECT_CONFIGURATION {
  struct _URB_HEADER            Hdr;
  PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor;
  USBD_CONFIGURATION_HANDLE     ConfigurationHandle;
  USBD_INTERFACE_INFORMATION    Interface;
};