typedef struct _WHEA_PCI_SLOT_NUMBER {
  union {
    struct {
      ULONG DeviceNumber : 5;
      ULONG FunctionNumber : 3;
      ULONG Reserved : 24;
    } bits;
    ULONG AsULONG;
  } u;
} WHEA_PCI_SLOT_NUMBER, *PWHEA_PCI_SLOT_NUMBER;