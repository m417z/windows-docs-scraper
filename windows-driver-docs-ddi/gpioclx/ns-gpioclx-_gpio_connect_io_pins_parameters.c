typedef struct _GPIO_CONNECT_IO_PINS_PARAMETERS {
  BANK_ID                    BankId;
  PPIN_NUMBER                PinNumberTable;
  USHORT                     PinCount;
  GPIO_CONNECT_IO_PINS_MODE  ConnectMode;
  UCHAR                      PullConfiguration;
  USHORT                     DebounceTimeout;
  USHORT                     DriveStrength;
  PVOID                      VendorData;
  ULONG                      VendorDataLength;
  GPIO_CONNECT_IO_PINS_FLAGS ConnectFlags;
} GPIO_CONNECT_IO_PINS_PARAMETERS, *PGPIO_CONNECT_IO_PINS_PARAMETERS;