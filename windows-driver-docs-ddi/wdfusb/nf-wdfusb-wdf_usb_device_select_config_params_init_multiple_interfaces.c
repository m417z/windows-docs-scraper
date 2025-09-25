VOID WDF_USB_DEVICE_SELECT_CONFIG_PARAMS_INIT_MULTIPLE_INTERFACES(
  [in, out]      PWDF_USB_DEVICE_SELECT_CONFIG_PARAMS Params,
  [in, optional] UCHAR                                NumberInterfaces,
  [in, optional] PWDF_USB_INTERFACE_SETTING_PAIR      SettingPairs
);