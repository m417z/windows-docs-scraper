typedef struct _DISK_DETECTION_INFO {
  ULONG          SizeOfDetectInfo;
  DETECTION_TYPE DetectionType;
  union {
    struct {
      DISK_INT13_INFO    Int13;
      DISK_EX_INT13_INFO ExInt13;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} DISK_DETECTION_INFO, *PDISK_DETECTION_INFO;