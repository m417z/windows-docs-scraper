typedef struct {
  EMI_MEASUREMENT_UNIT MeasurementUnit;
  WCHAR                HardwareOEM[EMI_NAME_MAX];
  WCHAR                HardwareModel[EMI_NAME_MAX];
  USHORT               HardwareRevision;
  USHORT               MeteredHardwareNameSize;
  WCHAR                MeteredHardwareName[ANYSIZE_ARRAY];
} EMI_METADATA_V1;