typedef struct _GPIO_WRITE_PINS_MASK_PARAMETERS {
  BANK_ID               BankId;
  ULONG64               SetMask;
  ULONG64               ClearMask;
  GPIO_WRITE_PINS_FLAGS Flags;
  PVOID                 Reserved;
} GPIO_WRITE_PINS_MASK_PARAMETERS, *PGPIO_WRITE_PINS_MASK_PARAMETERS;