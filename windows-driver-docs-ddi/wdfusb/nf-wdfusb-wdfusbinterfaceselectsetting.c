NTSTATUS WdfUsbInterfaceSelectSetting(
  [in]           WDFUSBINTERFACE                          UsbInterface,
  [in, optional] PWDF_OBJECT_ATTRIBUTES                   PipesAttributes,
  [in]           PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS Params
);