typedef struct _USB_CONFIGURATION_DESCRIPTOR {
  UCHAR  bLength;
  UCHAR  bDescriptorType;
  USHORT wTotalLength;
  UCHAR  bNumInterfaces;
  UCHAR  bConfigurationValue;
  UCHAR  iConfiguration;
  UCHAR  bmAttributes;
  UCHAR  MaxPower;
} USB_CONFIGURATION_DESCRIPTOR, *PUSB_CONFIGURATION_DESCRIPTOR;