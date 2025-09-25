# VDS_DRIVE_LETTER_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a drive letter.

## Members

### `wcLetter`

The drive letter.

### `volumeId`

The GUID of the volume object represented by the drive letter.

### `ulFlags`

The drive letter flags enumerated by [VDS_DRIVE_LETTER_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_drive_letter_flag).

### `bUsed`

If true, the drive letter is already in use; otherwise, the drive letter is available.

## Remarks

The [IVdsService::QueryDriveLetters](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-querydriveletters) method returns this structure to report the property details of a drive letter.

## See also

[IVdsService::QueryDriveLetters](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-querydriveletters)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DRIVE_LETTER_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_drive_letter_flag)