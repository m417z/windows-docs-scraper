typedef enum _VDS_STORAGE_IDENTIFIER_TYPE {
  VDSStorageIdTypeVendorSpecific = 0,
  VDSStorageIdTypeVendorId = 1,
  VDSStorageIdTypeEUI64 = 2,
  VDSStorageIdTypeFCPHName = 3,
  VDSStorageIdTypePortRelative = 4,
  VDSStorageIdTypeTargetPortGroup = 5,
  VDSStorageIdTypeLogicalUnitGroup = 6,
  VDSStorageIdTypeMD5LogicalUnitIdentifier = 7,
  VDSStorageIdTypeScsiNameString = 8
} VDS_STORAGE_IDENTIFIER_TYPE;