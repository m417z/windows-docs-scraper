typedef struct _BLUETOOTH_ADDRESS {
  union {
    BTH_ADDR ullLong;
    BYTE     rgBytes[6];
  };
} BLUETOOTH_ADDRESS_STRUCT;