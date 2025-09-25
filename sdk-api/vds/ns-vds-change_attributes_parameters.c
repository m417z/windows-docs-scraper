typedef struct _CHANGE_ATTRIBUTES_PARAMETERS {
  VDS_PARTITION_STYLE style;
  union {
    struct {
      BOOLEAN bootIndicator;
    } MbrPartInfo;
    struct {
      ULONGLONG attributes;
    } GptPartInfo;
  };
} CHANGE_ATTRIBUTES_PARAMETERS;