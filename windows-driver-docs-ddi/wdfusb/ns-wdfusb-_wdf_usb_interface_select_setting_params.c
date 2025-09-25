typedef struct _WDF_USB_INTERFACE_SELECT_SETTING_PARAMS {
  ULONG                               Size;
  WdfUsbTargetDeviceSelectSettingType Type;
  union {
    struct {
      PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor;
    } Descriptor;
    struct {
      UCHAR SettingIndex;
    } Interface;
    struct {
      PURB Urb;
    } Urb;
  } Types;
} WDF_USB_INTERFACE_SELECT_SETTING_PARAMS, *PWDF_USB_INTERFACE_SELECT_SETTING_PARAMS;