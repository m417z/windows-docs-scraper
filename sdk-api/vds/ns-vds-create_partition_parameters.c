typedef struct _CREATE_PARTITION_PARAMETERS {
  VDS_PARTITION_STYLE style;
  union {
    struct {
      BYTE    partitionType;
      BOOLEAN bootIndicator;
    } MbrPartInfo;
    struct {
      GUID      partitionType;
      GUID      partitionId;
      ULONGLONG attributes;
      WCHAR     name[36];
    } GptPartInfo;
  };
} CREATE_PARTITION_PARAMETERS;