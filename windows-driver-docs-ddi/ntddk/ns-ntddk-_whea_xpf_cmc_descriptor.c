typedef struct _WHEA_XPF_CMC_DESCRIPTOR {
  USHORT                       Type;
  BOOLEAN                      Enabled;
  UCHAR                        NumberOfBanks;
  ULONG                        Reserved;
  WHEA_NOTIFICATION_DESCRIPTOR Notify;
  WHEA_XPF_MC_BANK_DESCRIPTOR  Banks[WHEA_MAX_MC_BANKS];
} WHEA_XPF_CMC_DESCRIPTOR, *PWHEA_XPF_CMC_DESCRIPTOR;