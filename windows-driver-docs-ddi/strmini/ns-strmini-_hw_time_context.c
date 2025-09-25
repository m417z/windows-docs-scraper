typedef struct _HW_TIME_CONTEXT {
  struct _HW_DEVICE_EXTENSION *HwDeviceExtension;
  struct _HW_STREAM_OBJECT    *HwStreamObject;
  TIME_FUNCTION               Function;
  ULONGLONG                   Time;
  ULONGLONG                   SystemTime;
} HW_TIME_CONTEXT, *PHW_TIME_CONTEXT;