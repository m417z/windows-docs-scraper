typedef struct _USB_HUB_NAME {
  ULONG ActualLength;
  WCHAR HubName[1];
} USB_HUB_NAME, *PUSB_HUB_NAME;