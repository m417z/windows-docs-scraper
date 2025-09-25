typedef struct _WINBIO_SENSOR_ATTRIBUTES {
  DWORD                           PayloadSize;
  HRESULT                         WinBioHresult;
  WINBIO_VERSION                  WinBioVersion;
  WINBIO_BIOMETRIC_TYPE           SensorType;
  WINBIO_BIOMETRIC_SENSOR_SUBTYPE SensorSubType;
  WINBIO_CAPABILITIES             Capabilities;
  WINBIO_STRING                   ManufacturerName;
  WINBIO_STRING                   ModelName;
  WINBIO_STRING                   SerialNumber;
  WINBIO_VERSION                  FirmwareVersion;
  DWORD                           SupportedFormatEntries;
  WINBIO_REGISTERED_FORMAT        SupportedFormat[1];
} WINBIO_SENSOR_ATTRIBUTES, *PWINBIO_SENSOR_ATTRIBUTES;