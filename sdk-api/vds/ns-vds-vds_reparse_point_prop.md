# VDS_REPARSE_POINT_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the reparse-point properties of a [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

## Members

### `SourceVolumeId`

The GUID of the volume object that contains the reparse point.

### `pwszPath`

A string for a path without a drive letter. For example, "\mount".

## Remarks

The [IVdsVolumeMF::QueryReparsePoints](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-queryreparsepoints) method returns this structure to report the reparse-point properties of a [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

## See also

[IVdsVolumeMF::QueryReparsePoints](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf-queryreparsepoints)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)