typedef enum _USBFN_ATTACH_ACTION {
  UsbfnPortDetected,
  UsbfnPortDetectedNoCad,
  UsbfnProceedWithAttach,
  UsbfnIgnoreAttach,
  UsbfnDetectProprietaryCharger,
  UsbfnHwBasedChargerDetection
} USBFN_ATTACH_ACTION, *PUSBFN_ATTACH_ACTION;