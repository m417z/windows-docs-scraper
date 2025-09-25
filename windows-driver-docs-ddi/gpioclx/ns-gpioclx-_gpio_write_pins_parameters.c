typedef struct _GPIO_WRITE_PINS_PARAMETERS {
  BANK_ID               BankId;
  PPIN_NUMBER           PinNumberTable;
  ULONG                 PinCount;
  PVOID                 Buffer;
  GPIO_WRITE_PINS_FLAGS Flags;
  PVOID                 Reserved;
} GPIO_WRITE_PINS_PARAMETERS, *PGPIO_WRITE_PINS_PARAMETERS;