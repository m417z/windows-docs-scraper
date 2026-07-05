typedef union _BUS_SPECIFIC_RESET_FLAGS {
  struct {
    ULONGLONG KeepStackReset : 1;
    ULONGLONG EnablePciHotPlugThroughPcr : 1;
    ULONGLONG EnablePciDllsceThroughPcr : 1;
    ULONGLONG DisablePciLinkThroughPcr : 1;
    ULONGLONG Reserved : 60;
  } u;
  ULONGLONG AsUlonglong;
} BUS_SPECIFIC_RESET_FLAGS, *PBUS_SPECIFIC_RESET_FLAGS;