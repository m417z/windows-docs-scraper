typedef struct _USB_BUS_NOTIFICATION {
  USB_NOTIFICATION_TYPE NotificationType;
  ULONG                 TotalBandwidth;
  ULONG                 ConsumedBandwidth;
  ULONG                 ControllerNameLength;
} USB_BUS_NOTIFICATION, *PUSB_BUS_NOTIFICATION;