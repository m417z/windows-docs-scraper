typedef struct _ATTACH_VIRTUAL_DISK_PARAMETERS {
  ATTACH_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      ULONG Reserved;
    } Version1;
    struct {
      ULONGLONG RestrictedOffset;
      ULONGLONG RestrictedLength;
    } Version2;
  };
} ATTACH_VIRTUAL_DISK_PARAMETERS, *PATTACH_VIRTUAL_DISK_PARAMETERS;