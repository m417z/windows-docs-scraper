typedef enum _USBFN_PORT_TYPE {
  UsbfnUnknownPort,
  UsbfnStandardDownstreamPort,
  UsbfnChargingDownstreamPort,
  UsbfnDedicatedChargingPort,
  UsbfnInvalidDedicatedChargingPort,
  UsbfnProprietaryDedicatedChargingPort,
  UsbfnPortTypeMaximum
} USBFN_PORT_TYPE, *PUSBFN_PORT_TYPE;