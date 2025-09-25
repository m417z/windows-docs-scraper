typedef struct _DXGK_BRIGHTNESS_SET_IN {
  UINT32                      BrightnessMillinits;
  UINT32                      TransitionTimeMs;
  DXGK_BRIGHTNESS_SENSOR_DATA SensorReadings;
} DXGK_BRIGHTNESS_SET_IN, *PDXGK_BRIGHTNESS_SET_IN;