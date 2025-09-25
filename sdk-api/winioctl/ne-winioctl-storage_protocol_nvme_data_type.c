typedef enum _STORAGE_PROTOCOL_NVME_DATA_TYPE {
  NVMeDataTypeUnknown = 0,
  NVMeDataTypeIdentify,
  NVMeDataTypeLogPage,
  NVMeDataTypeFeature,
  NVMeDataTypeLogPageEx,
  NVMeDataTypeFeatureEx
} STORAGE_PROTOCOL_NVME_DATA_TYPE, *PSTORAGE_PROTOCOL_NVME_DATA_TYPE;