typedef struct _CABINET_INFO_W {
  PCWSTR CabinetPath;
  PCWSTR CabinetFile;
  PCWSTR DiskName;
  USHORT SetId;
  USHORT CabinetNumber;
} CABINET_INFO_W, *PCABINET_INFO_W;