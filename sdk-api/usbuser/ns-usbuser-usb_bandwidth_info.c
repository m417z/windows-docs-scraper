typedef struct _USB_BANDWIDTH_INFO {
  ULONG DeviceCount;
  ULONG TotalBusBandwidth;
  ULONG Total32secBandwidth;
  ULONG AllocedBulkAndControl;
  ULONG AllocedIso;
  ULONG AllocedInterrupt_1ms;
  ULONG AllocedInterrupt_2ms;
  ULONG AllocedInterrupt_4ms;
  ULONG AllocedInterrupt_8ms;
  ULONG AllocedInterrupt_16ms;
  ULONG AllocedInterrupt_32ms;
} USB_BANDWIDTH_INFO, *PUSB_BANDWIDTH_INFO;