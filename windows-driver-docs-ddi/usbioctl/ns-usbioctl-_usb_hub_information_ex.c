typedef struct _USB_HUB_INFORMATION_EX {
  USB_HUB_TYPE HubType;
  USHORT       HighestPortNumber;
  union {
    USB_HUB_DESCRIPTOR    UsbHubDescriptor;
    USB_30_HUB_DESCRIPTOR Usb30HubDescriptor;
  } u;
} USB_HUB_INFORMATION_EX, *PUSB_HUB_INFORMATION_EX;