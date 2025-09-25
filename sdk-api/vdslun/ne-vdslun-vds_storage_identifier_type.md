# VDS_STORAGE_IDENTIFIER_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a storage identifier.

## Constants

### `VDSStorageIdTypeVendorSpecific:0`

The storage identifier type is vendor specific.

### `VDSStorageIdTypeVendorId:1`

The storage identifier is the same as the vendor identifier.

### `VDSStorageIdTypeEUI64:2`

The storage identifier type follows the IEEE 64-bit Extended Unique Identifier (EUI-64) standard.

### `VDSStorageIdTypeFCPHName:3`

The storage identifier type follows the Fibre Channel Physical and Signaling Interface (FC-PH) naming
convention.

### `VDSStorageIdTypePortRelative:4`

**VDS 1.1:** The storage identifier type is dependent on the port.

### `VDSStorageIdTypeTargetPortGroup:5`

### `VDSStorageIdTypeLogicalUnitGroup:6`

### `VDSStorageIdTypeMD5LogicalUnitIdentifier:7`

### `VDSStorageIdTypeScsiNameString:8`

### `VDSStorageIdTypeSCSINameString`

**VDS 1.1:** The storage identifier type follows the SCSI naming convention. See SCSI Primary Commands - 3 (SPC-3) for
more details.

## Remarks

The [VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier) structure
includes a **VDS_STORAGE_IDENTIFIER_TYPE** value as a member to indicate the storage identifier type.

**Note** Additional constants might be added to the **VDS_STORAGE_IDENTIFIER_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_STORAGE_IDENTIFIER_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)