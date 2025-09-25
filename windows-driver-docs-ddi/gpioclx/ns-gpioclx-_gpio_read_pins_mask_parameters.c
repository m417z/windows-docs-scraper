typedef struct _GPIO_READ_PINS_MASK_PARAMETERS {
  BANK_ID              BankId;
  PULONG64             PinValues;
  GPIO_READ_PINS_FLAGS Flags;
  PVOID                Reserved;
} GPIO_READ_PINS_MASK_PARAMETERS, *PGPIO_READ_PINS_MASK_PARAMETERS;