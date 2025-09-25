typedef struct _WHEA_PACKET_LOG_DATA {
  UCHAR                                    LogData[WHEA_MAX_LOG_DATA_LEN];
  UCHAR                                    ExtraBytes[WHEA_MAX_LOG_DATA_LEN];
  ULONG_PTR                                BcParam3;
  ULONG_PTR                                BcParam4;
  ULONG                                    LogDataLength;
  USHORT                                   LogTag;
  USHORT                                   Reserved;
  WHEA_REPORT_HW_ERROR_DEVICE_DRIVER_FLAGS Flags;
} WHEA_PACKET_LOG_DATA, *PWHEA_PACKET_LOG_DATA;