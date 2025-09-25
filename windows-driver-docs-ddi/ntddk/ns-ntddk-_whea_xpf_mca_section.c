typedef struct _WHEA_XPF_MCA_SECTION {
  ULONG             VersionNumber;
  WHEA_CPU_VENDOR   CpuVendor;
  LARGE_INTEGER     Timestamp;
  ULONG             ProcessorNumber;
  MCG_STATUS        GlobalStatus;
  ULONGLONG         InstructionPointer;
  ULONG             BankNumber;
  MCI_STATUS        Status;
  ULONGLONG         Address;
  ULONGLONG         Misc;
  ULONG             ExtendedRegisterCount;
  ULONG             ApicId;
  union {
    ULONGLONG                   ExtendedRegisters[WHEA_XPF_MCA_EXTREG_MAX_COUNT];
    WHEA_AMD_EXTENDED_REGISTERS AMDExtendedRegisters;
  };
  MCG_CAP           GlobalCapability;
  XPF_RECOVERY_INFO RecoveryInfo;
  ULONG             ExBankCount;
  ULONG             BankNumberEx[WHEA_XPF_MCA_EXBANK_COUNT];
  MCI_STATUS        StatusEx[WHEA_XPF_MCA_EXBANK_COUNT];
  ULONGLONG         AddressEx[WHEA_XPF_MCA_EXBANK_COUNT];
  ULONGLONG         MiscEx[WHEA_XPF_MCA_EXBANK_COUNT];
} WHEA_XPF_MCA_SECTION, *PWHEA_XPF_MCA_SECTION;