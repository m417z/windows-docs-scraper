typedef struct _DXGK_BRIGHTNESS_SENSOR_DATA {
  UINT32                                   Size;
  union {
    struct {
      UINT AlsReadingValid : 1;
      UINT ChromaticityValid : 1;
      UINT ColorTemperatureValid : 1;
      UINT Reserved : 29;
    } Flags;
    UINT ValidSensorValues;
  };
  float                                    AlsReading;
  DXGK_BRIGHTNESS_SENSOR_DATA_CHROMATICITY Chromaticity;
  float                                    ColorTemperature;
} DXGK_BRIGHTNESS_SENSOR_DATA;