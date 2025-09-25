# VDS_STORAGE_IDENTIFIER_CODE_SET enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of the valid code sets (encodings) of a storage identifier.

## Constants

### `VDSStorageIdCodeSetReserved:0`

This value is reserved.

### `VDSStorageIdCodeSetBinary:1`

The storage identifier is encoded as binary data.

### `VDSStorageIdCodeSetAscii:2`

The storage identifier is encoded as ASCII data.

### `VDSStorageIdCodeSetUtf8:3`

The storage identifier is encoded as UTF-8.

**Windows Vista and Windows Server 2003:** Not supported before Windows Vista with SP1 and Windows Server 2008.

## Remarks

The [VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier) structure includes
a **VDS_STORAGE_IDENTIFIER_CODE_SET** value as a member to indicate the code set of a storage identifier.

**Note** Additional constants might be added to the **VDS_STORAGE_IDENTIFIER_CODE_SET** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_STORAGE_IDENTIFIER_CODE_SET** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_STORAGE_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_storage_identifier)