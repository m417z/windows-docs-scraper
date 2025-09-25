typedef struct _IRB_REQ_GET_CONFIGURATION_INFORMATION {
  PCONFIG_ROM   ConfigRom;
  ULONG         UnitDirectoryBufferSize;
  PVOID         UnitDirectory;
  IO_ADDRESS    UnitDirectoryLocation;
  ULONG         UnitDependentDirectoryBufferSize;
  PVOID         UnitDependentDirectory;
  IO_ADDRESS    UnitDependentDirectoryLocation;
  ULONG         VendorLeafBufferSize;
  PTEXTUAL_LEAF VendorLeaf;
  ULONG         ModelLeafBufferSize;
  PTEXTUAL_LEAF ModelLeaf;
} IRB_REQ_GET_CONFIGURATION_INFORMATION;