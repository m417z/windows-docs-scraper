typedef struct _WHEA_XPF_MC_BANK_DESCRIPTOR {
  UCHAR             BankNumber;
  BOOLEAN           ClearOnInitialization;
  UCHAR             StatusDataFormat;
  XPF_MC_BANK_FLAGS Flags;
  ULONG             ControlMsr;
  ULONG             StatusMsr;
  ULONG             AddressMsr;
  ULONG             MiscMsr;
  ULONGLONG         ControlData;
} WHEA_XPF_MC_BANK_DESCRIPTOR, *PWHEA_XPF_MC_BANK_DESCRIPTOR;