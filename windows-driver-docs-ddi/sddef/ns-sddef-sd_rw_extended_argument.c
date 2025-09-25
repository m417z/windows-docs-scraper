typedef struct _SD_RW_EXTENDED_ARGUMENT {
  union {
    struct {
      ULONG Count : 9;
      ULONG Address : 17;
      ULONG OpCode : 1;
      ULONG BlockMode : 1;
      ULONG Function : 3;
      ULONG WriteToDevice : 1;
    } bits;
    ULONG AsULONG;
  } u;
} SD_RW_EXTENDED_ARGUMENT, *PSD_RW_EXTENDED_ARGUMENT;