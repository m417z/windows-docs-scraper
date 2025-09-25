## Description

The STORAGE\_IDENTIFIER\_TYPE enumeration specifies the type of storage identifier.

## Constants

### `StorageIdTypeVendorSpecific`

Indicates that the vendor created the identifier without reference to an assignment authority, and consequently there is no guarantee that the identifier is globally unique.

### `StorageIdTypeVendorId`

Indicates a vendor identifier strings assigned by the SCSI-3 specification to the vendor.

### `StorageIdTypeEUI64`

Indicates a 64-bit IEEE extended unique identifier (EUI-64).

### `StorageIdTypeFCPHName`

Indicates a 64-bit FC-PH name identifier as defined in the *X3.230-1994* specification.

### `StorageIdTypePortRelative`

Indicates that the identifier type depends on the port.

### `StorageIdTypeTargetPortGroup`

The storage identifier is a target port group number.

### `StorageIdTypeLogicalUnitGroup`

The storage identifier is a logical unit group number.

### `StorageIdTypeMD5LogicalUnitIdentifier`

The storage identifier is an MD5 logical unit number (LUN).

### `StorageIdTypeScsiNameString`

Indicates that the identifier type is specified by a Scsi name string.

## See also

[**STORAGE\_IDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_identifier)