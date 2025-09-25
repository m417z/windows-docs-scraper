# _FILE_FS_OBJECTID_INFORMATION structure

## Description

The FILE_FS_OBJECTID_INFORMATION structure is used to query or set the object ID for a file system volume.

## Members

### `ObjectId`

A 16-byte GUID that identifies the file system volume on the disk.

### `ExtendedInfo`

A 48-byte value containing optional, additional caller-defined information on the file system volume. The meaning of this extended information is opaque to the file system.

## Remarks

This information can be queried in either of the following ways:

* Call [**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation) or [**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwqueryvolumeinformationfile), passing FileFsObjectIdInformation as the value of *FileInformationClass* and passing a caller-allocated, FILE_FS_OBJECTID_INFORMATION-structured buffer as the value of *FileInformation*.
* Create an IRP with major function code IRP_MJ_QUERY_VOLUME_INFORMATION.

No specific access rights are required to query this information. Thus this information is available as long as the volume is accessed through an open handle to the volume itself, or to a file or directory on the volume.

This information can be set in either of the following ways:

* Call [**FltSetVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation) or [**ZwSetVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwsetvolumeinformationfile), passing FileFsObjectIdInformation as the value of *FileInformationClass* and passing a caller-allocated, FILE_FS_OBJECTID_INFORMATION-structured buffer as the value of *FileInformation*.
* Create an IRP with major function code IRP_MJ_SET_VOLUME_INFORMATION.

FILE_WRITE_DATA access to the volume is required to set this information.

Support for volume object IDs is file-system-specific. In NTFS, volume object IDs are used extensively by the distributed link tracking service.

It is important to note that the volume object ID is not the same as the volume GUID. The *volume object ID* is assigned to the file system volume by the file system. The *volume GUID*, or *unique volume name*, is file system-independent; it is assigned to the underlying storage volume by the Volume Mount Manager.

To get the volume GUID for a volume, use the Win32 [**GetVolumeNameForVolumeMountPointW**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getvolumenameforvolumemountpointw) function or the [**FltGetVolumeGuidName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname) routine.

The size of the buffer passed in the *FileInformation* parameter to **FltQueryVolumeInformation**, **FltSetVolumeInformation**, **ZwQueryVolumeInformationFile**, or **ZwSetVolumeInformationFile** must be at least **sizeof** (FILE_FS_OBJECTID_INFORMATION).

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[**FltGetVolumeGuidName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumeguidname)

[**FltQueryVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformation)

[**FltSetVolumeInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumeinformation)

[**IRP_MJ_QUERY_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information)

[**IRP_MJ_SET_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-volume-information)

[**ZwQueryVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwqueryvolumeinformationfile)

[**ZwSetVolumeInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwsetvolumeinformationfile)