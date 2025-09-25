VOID WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_INTERFACES_DESCRIPTORS(
  [out] PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params,
  [in]  PUSB_CONFIGURATION_DESCRIPTOR        ConfigDescriptor,
  [in]  PUSB_INTERFACE_DESCRIPTOR            *InterfaceDescriptors,
  [in]  ULONG                                NumInterfaceDescriptors
);