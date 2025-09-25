typedef struct _WDF_USB_DEVICE_INFORMATION {
  ULONG                    Size;
  USBD_VERSION_INFORMATION UsbdVersionInformation;
  ULONG                    HcdPortCapabilities;
  ULONG                    Traits;
} WDF_USB_DEVICE_INFORMATION, *PWDF_USB_DEVICE_INFORMATION;