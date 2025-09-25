typedef enum _STORAGE_PROTOCOL_UFS_DATA_TYPE {
  UfsDataTypeUnknown = 0,
  UfsDataTypeQueryDescriptor,
  UfsDataTypeQueryAttribute,
  UfsDataTypeQueryFlag,
  UfsDataTypeQueryDmeAttribute,
  UfsDataTypeQueryDmePeerAttribute,
  UfsDataTypeMax
} STORAGE_PROTOCOL_UFS_DATA_TYPE, *PSTORAGE_PROTOCOL_UFS_DATA_TYPE;