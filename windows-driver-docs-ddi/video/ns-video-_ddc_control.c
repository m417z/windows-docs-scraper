typedef struct _DDC_CONTROL {
  IN ULONG         Size;
  IN I2C_CALLBACKS I2CCallbacks;
  IN UCHAR         EdidSegment;
} DDC_CONTROL, *PDDC_CONTROL;