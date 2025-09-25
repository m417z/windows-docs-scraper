typedef union _LPI_STATE_FLAGS {
  struct {
    ULONG Disabled : 1;
    ULONG CounterUnavailable : 1;
    ULONG Reserved : 30;
  };
  ULONG  AsUlong;
} LPI_STATE_FLAGS, *PLPI_STATE_FLAGS;