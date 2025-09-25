typedef struct _IRB_REQ_GET_CONFIG_ROM {
  ULONG GenerationCount;
  PCROM ConfigRom;
  ULONG UnitDirectoryIndex;
  ULONG UnitDependentDirectoryIndex;
  ULONG VendorLeafIndex;
  ULONG ModelLeafIndex;
} IRB_REQ_GET_CONFIG_ROM;