typedef union _BUS_SPECIFIC_RESET_FLAGS {
  struct {
    ULONGLONG KeepStackReset : 1;
    ULONGLONG Reserved : 63;
  } u;
  ULONGLONG AsUlonglong;
} BUS_SPECIFIC_RESET_FLAGS, *PBUS_SPECIFIC_RESET_FLAGS;