# FILE_OBJECTID_INFORMATION structure

## Description

The **FILE_OBJECTID_INFORMATION** structure is used to query object ID information for the files in a directory on an NTFS volume.

## Members

### `FileReference`

The 8-byte file reference number for the file. NTFS generates this number and assigns it to the file automatically when the file is created.

### `ObjectId`

The 16-byte file object ID for the file. NTFS generates this number and assigns it to the file at the request of a driver or application. File object IDs are guaranteed to be unique only within the volume where the file resides.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.BirthVolumeId`

The object identifier of the volume on which the file resided when the object identifier was created, or zero if the volume had no object identifier at that time. After copy operations, move operations, or other file operations, **BirthVolumeId** may not be the same as the object identifier of the volume on which the object currently resides.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.BirthObjectId`

 The object identifier of the file at the time it was created. After copy operations, move operations, or other file operations **BirthObjectId** may not be the same as the current value of the **ObjectId** member.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DomainId`

Reserved; must be zero.

### `DUMMYUNIONNAME.ExtendedInfo`

User-provided data. You can use it to contain the **BirthVolumeID**, **BirthObjectID**, and **DomainID** members, or you can define a different data structure.

## Remarks

This information can be queried in either of the following ways:

* Call [ZwQueryDirectoryFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfile), passing FileObjectIdInformation as the value of **FileInformationClass** and passing a caller-allocated, **FILE_OBJECTID_INFORMATION**-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code IRP_MJ_DIRECTORY_CONTROL and minor function code IRP_MN_QUERY_DIRECTORY.

No special access rights are required to query for this information.

Support for file reference numbers and file object IDs is file system-specific:

* File object IDs are supported only on NTFS volumes. NTFS allows files to be opened by object ID as well as by file reference number.
* ReFS doesn't support object IDs. ReFS uses 128-bit file IDs, so can't cleanly distinguish between file ID versus object ID when processing an open by ID. (File IDs are 64-bits on NTFS, so are easily distinguished from object IDs. NTFS also simultaneously supports opening by 128-bit ID: if the high 64-bits are zero, the low 64-bits are treated as a file ID; otherwise, the 128-bit value is treated as an object ID.)

File system filter drivers that use file object IDs should be tested for interoperability with DFS, the Replicator service, and the Distributed Link Tracking service, all of which use and manipulate file object IDs.

This structure must be aligned on a LONG (4-byte) boundary.

## See also

[FILE_INTERNAL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_internal_information)

[IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[ZwQueryDirectoryFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfile)