typedef struct _SD_RW_DIRECT_ARGUMENT {
  union {
    struct {
      ULONG Data : 8;
      ULONG Reserved1 : 1;
      ULONG Address : 17;
      ULONG Reserved2 : 1;
      ULONG ReadAfterWrite : 1;
      ULONG Function : 3;
      ULONG WriteToDevice : 1;
    } bits;
    ULONG AsULONG;
  } u;
} SD_RW_DIRECT_ARGUMENT, *PSD_RW_DIRECT_ARGUMENT;