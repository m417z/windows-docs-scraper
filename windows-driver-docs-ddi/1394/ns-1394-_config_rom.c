typedef struct _CONFIG_ROM {
  ULONG CR_Info;
  ULONG CR_Signiture;
  ULONG CR_BusInfoBlockCaps;
  ULONG CR_Node_UniqueID[2];
  ULONG CR_Root_Info;
} CONFIG_ROM, *PCONFIG_ROM;