typedef struct {
  ULONGLONG           ErrorCount;
  USHORT              SQID;
  USHORT              CMDID;
  NVME_COMMAND_STATUS Status;
  struct {
    USHORT Byte : 8;
    USHORT Bit : 3;
    USHORT Reserved : 5;
  } ParameterErrorLocation;
  ULONGLONG           Lba;
  ULONG               NameSpace;
  UCHAR               VendorInfoAvailable;
  UCHAR               Reserved0[3];
  ULONGLONG           CommandSpecificInfo;
  UCHAR               Reserved1[24];
} NVME_ERROR_INFO_LOG, *PNVME_ERROR_INFO_LOG;