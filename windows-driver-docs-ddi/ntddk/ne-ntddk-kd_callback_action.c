typedef enum {
  KdConfigureDeviceAndContinue,
  KdSkipDeviceAndContinue,
  KdConfigureDeviceAndStop,
  KdSkipDeviceAndStop
} KD_CALLBACK_ACTION, *PKD_CALLBACK_ACTION;