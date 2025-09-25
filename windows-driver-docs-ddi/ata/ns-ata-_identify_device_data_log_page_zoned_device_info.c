typedef struct _IDENTIFY_DEVICE_DATA_LOG_PAGE_ZONED_DEVICE_INFO {
  IDENTIFY_DEVICE_DATA_LOG_PAGE_HEADER Header;
  struct {
    ULONGLONG URSWRZ : 1;
    ULONGLONG Reserved : 62;
    ULONGLONG Valid : 1;
  } ZonedDeviceCapabilities;
  struct {
    ULONGLONG Reserved : 63;
    ULONGLONG Valid : 1;
  } ZonedDeviceSettings;
  struct {
    ULONGLONG Number : 32;
    ULONGLONG Reserved : 31;
    ULONGLONG Valid : 1;
  } OptimalNumberOfOpenSequentialWritePreferredZones;
  struct {
    ULONGLONG Number : 32;
    ULONGLONG Reserved : 31;
    ULONGLONG Valid : 1;
  } OptimalNumberOfNonSequentiallyWrittenSequentialWritePreferredZones;
  struct {
    ULONGLONG Number : 32;
    ULONGLONG Reserved : 31;
    ULONGLONG Valid : 1;
  } MaxNumberOfOpenSequentialWriteRequiredZones;
  struct {
    ULONGLONG ZacMinorVersion : 16;
    ULONGLONG Reserved0 : 47;
    ULONGLONG Valid : 1;
  } Version;
  UCHAR                                Reserved[456];
} IDENTIFY_DEVICE_DATA_LOG_PAGE_ZONED_DEVICE_INFO, *PIDENTIFY_DEVICE_DATA_LOG_PAGE_ZONED_DEVICE_INFO;