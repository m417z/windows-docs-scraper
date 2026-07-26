typedef struct _inputQPSettings {
  UINT32                          minBlockSize;
  UINT32                          maxBlockSize;
  UINT32                          stepsBlockSize;
  eAVEncVideoQPMapElementDataType dataType;
  INT16                           minValue;
  INT16                           maxValue;
  UINT16                          step;
} InputQPSettings;