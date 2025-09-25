typedef struct _GPIO_READ_PINS_PARAMETERS {
  BANK_ID              BankId;
  PPIN_NUMBER          PinNumberTable;
  ULONG                PinCount;
  PVOID                Buffer;
  GPIO_READ_PINS_FLAGS Flags;
  PVOID                Reserved;
} GPIO_READ_PINS_PARAMETERS, *PGPIO_READ_PINS_PARAMETERS;