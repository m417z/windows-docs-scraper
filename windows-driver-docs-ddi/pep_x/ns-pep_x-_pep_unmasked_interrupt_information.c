typedef struct _PEP_UNMASKED_INTERRUPT_INFORMATION {
  USHORT                       Version;
  USHORT                       Size;
  PEP_UNMASKED_INTERRUPT_FLAGS Flags;
  KINTERRUPT_MODE              Mode;
  KINTERRUPT_POLARITY          Polarity;
  ULONG                        Gsiv;
  USHORT                       PinNumber;
  PEPHANDLE                    DeviceHandle;
} PEP_UNMASKED_INTERRUPT_INFORMATION, *PPEP_UNMASKED_INTERRUPT_INFORMATION;