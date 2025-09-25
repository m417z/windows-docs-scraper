typedef enum _USBFN_EVENT {
  UsbfnEventMinimum,
  UsbfnEventAttach,
  UsbfnEventReset,
  UsbfnEventDetach,
  UsbfnEventSuspend,
  UsbfnEventResume,
  UsbfnEventSetupPacket,
  UsbfnEventConfigured,
  UsbfnEventUnConfigured,
  UsbfnEventPortType,
  UsbfnEventBusTearDown,
  UsbfnEventSetInterface,
  UsbfnEventMaximum
} USBFN_EVENT, *PUSBFN_EVENT;