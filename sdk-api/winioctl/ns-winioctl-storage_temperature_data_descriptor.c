typedef struct _STORAGE_TEMPERATURE_DATA_DESCRIPTOR {
  DWORD                    Version;
  DWORD                    Size;
  SHORT                    CriticalTemperature;
  SHORT                    WarningTemperature;
  WORD                     InfoCount;
  BYTE                     Reserved0[2];
  DWORD                    Reserved1[2];
  STORAGE_TEMPERATURE_INFO TemperatureInfo[ANYSIZE_ARRAY];
} STORAGE_TEMPERATURE_DATA_DESCRIPTOR, *PSTORAGE_TEMPERATURE_DATA_DESCRIPTOR;