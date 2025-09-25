typedef struct _GPIO_ENABLE_INTERRUPT_PARAMETERS {
  BANK_ID                     BankId;
  PIN_NUMBER                  PinNumber;
  GPIO_ENABLE_INTERRUPT_FLAGS Flags;
  KINTERRUPT_MODE             InterruptMode;
  KINTERRUPT_POLARITY         Polarity;
  UCHAR                       PullConfiguration;
  USHORT                      DebounceTimeout;
  PVOID                       VendorData;
  ULONG                       VendorDataLength;
} GPIO_ENABLE_INTERRUPT_PARAMETERS, *PGPIO_ENABLE_INTERRUPT_PARAMETERS;