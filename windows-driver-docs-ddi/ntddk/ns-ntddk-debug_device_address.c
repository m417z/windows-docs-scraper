typedef struct {
  UCHAR   Type;
  BOOLEAN Valid;
  union {
    UCHAR Reserved[2];
    struct {
      UCHAR BitWidth;
      UCHAR AccessSize;
    };
  };
  PUCHAR  TranslatedAddress;
  ULONG   Length;
} DEBUG_DEVICE_ADDRESS, *PDEBUG_DEVICE_ADDRESS;