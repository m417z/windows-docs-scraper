typedef struct _USB_BUS_INFORMATION_LEVEL_1 {
  ULONG TotalBandwidth;
  ULONG ConsumedBandwidth;
  ULONG ControllerNameLength;
  WCHAR ControllerNameUnicodeString[1];
} USB_BUS_INFORMATION_LEVEL_1, *PUSB_BUS_INFORMATION_LEVEL_1;