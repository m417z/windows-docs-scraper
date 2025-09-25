typedef struct {
  ULONG                   Size;
  ULONG                   Version;
  GNSS_DRIVERCOMMAND_TYPE CommandType;
  ULONG                   Reserved;
  ULONG                   CommandDataSize;
  BYTE                    Unused[512];
  BYTE                    CommandData[ANYSIZE_ARRAY];
} GNSS_DRIVERCOMMAND_PARAM, *PGNSS_DRIVERCOMMAND_PARAM;