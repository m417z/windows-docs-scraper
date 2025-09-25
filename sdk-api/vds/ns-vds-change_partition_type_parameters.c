typedef struct _CHANGE_PARTITION_TYPE_PARAMETERS {
  VDS_PARTITION_STYLE style;
  union {
    struct {
      BYTE partitionType;
    } MbrPartInfo;
    struct {
      GUID partitionType;
    } GptPartInfo;
  };
} CHANGE_PARTITION_TYPE_PARAMETERS;