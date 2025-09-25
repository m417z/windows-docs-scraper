typedef enum _WdfUsbTargetDeviceSelectConfigType {
  WdfUsbTargetDeviceSelectConfigTypeInvalid = 0,
  WdfUsbTargetDeviceSelectConfigTypeDeconfig = 1,
  WdfUsbTargetDeviceSelectConfigTypeSingleInterface = 2,
  WdfUsbTargetDeviceSelectConfigTypeMultiInterface = 3,
  WdfUsbTargetDeviceSelectConfigTypeInterfacesPairs = 4,
  WdfUsbTargetDeviceSelectConfigTypeInterfacesDescriptor = 5,
  WdfUsbTargetDeviceSelectConfigTypeUrb = 6
} WdfUsbTargetDeviceSelectConfigType;