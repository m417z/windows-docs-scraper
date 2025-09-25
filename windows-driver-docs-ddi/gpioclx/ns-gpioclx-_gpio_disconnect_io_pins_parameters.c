typedef struct _GPIO_DISCONNECT_IO_PINS_PARAMETERS {
  BANK_ID                       BankId;
  PPIN_NUMBER                   PinNumberTable;
  ULONG                         PinCount;
  GPIO_CONNECT_IO_PINS_MODE     DisconnectMode;
  GPIO_DISCONNECT_IO_PINS_FLAGS DisconnectFlags;
} GPIO_DISCONNECT_IO_PINS_PARAMETERS, *PGPIO_DISCONNECT_IO_PINS_PARAMETERS;