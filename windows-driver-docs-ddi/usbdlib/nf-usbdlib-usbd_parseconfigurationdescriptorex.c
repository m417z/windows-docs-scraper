PUSB_INTERFACE_DESCRIPTOR USBD_ParseConfigurationDescriptorEx(
  [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
  [in] PVOID                         StartPosition,
  [in] LONG                          InterfaceNumber,
  [in] LONG                          AlternateSetting,
  [in] LONG                          InterfaceClass,
  [in] LONG                          InterfaceSubClass,
  [in] LONG                          InterfaceProtocol
);