typedef struct _UMDETW_ALLOCATION_USAGE {
  union {
    struct {
      UINT Packed : 1;
      UINT Renamed : 1;
      UINT Reserved : 14;
      UINT DriverReserved : 16;
    };
    UINT Value;
  };
} UMDETW_ALLOCATION_USAGE;