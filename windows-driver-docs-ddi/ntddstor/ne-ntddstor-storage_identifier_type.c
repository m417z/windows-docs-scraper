typedef enum _STORAGE_IDENTIFIER_TYPE {
  StorageIdTypeVendorSpecific,
  StorageIdTypeVendorId,
  StorageIdTypeEUI64,
  StorageIdTypeFCPHName,
  StorageIdTypePortRelative,
  StorageIdTypeTargetPortGroup,
  StorageIdTypeLogicalUnitGroup,
  StorageIdTypeMD5LogicalUnitIdentifier,
  StorageIdTypeScsiNameString
} STORAGE_IDENTIFIER_TYPE, *PSTORAGE_IDENTIFIER_TYPE;