typedef struct _WHEA_XPF_MCE_DESCRIPTOR {
  USHORT                      Type;
  UCHAR                       Enabled;
  UCHAR                       NumberOfBanks;
  XPF_MCE_FLAGS               Flags;
  ULONGLONG                   MCG_Capability;
  ULONGLONG                   MCG_GlobalControl;
  WHEA_XPF_MC_BANK_DESCRIPTOR Banks[WHEA_MAX_MC_BANKS];
} WHEA_XPF_MCE_DESCRIPTOR, *PWHEA_XPF_MCE_DESCRIPTOR;