# VDS_DRIVE_LETTER_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a drive letter.

## Constants

### `VDS_DLF_NON_PERSISTENT:0x1`

If set, the drive letter disappears after the computer reboots.

## Remarks

This enumeration provides the values for the *ulFlags* member of the [VDS_DRIVE_LETTER_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_drive_letter_prop) structure.

**Note** Additional constants might be added to the **VDS_DRIVE_LETTER_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_DRIVE_LETTER_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)