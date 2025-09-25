typedef struct _OPEN_VIRTUAL_DISK_PARAMETERS {
  OPEN_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      ULONG RWDepth;
    } Version1;
    struct {
      BOOL GetInfoOnly;
      BOOL ReadOnly;
      GUID ResiliencyGuid;
    } Version2;
  };
} OPEN_VIRTUAL_DISK_PARAMETERS, *POPEN_VIRTUAL_DISK_PARAMETERS;