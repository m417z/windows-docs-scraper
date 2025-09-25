# FILE_INTERNAL_INFORMATION structure

## Description

The **FILE_INTERNAL_INFORMATION** structure is used to query for the file system's 8-byte file reference number for a file.

## Members

### `IndexNumber`

The 8-byte file reference number for the file. This number is assigned by the file system and is file-system-specific. (Note that this is not the same as the 16-byte "file object ID" that was added to NTFS for Microsoft Windows 2000.)

## Remarks

This information can be queried in either of the following ways:

* Call [**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile) or [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile), passing FileInternalInformation as the value of **FileInformationClass** and passing a caller-allocated, FILE_INTERNAL_INFORMATION-structured buffer as the value of **FileInformation**.

* Create an IRP with major function code [**IRP_MJ_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information).

No specific access rights are required to query this information.

The **IndexNumber** member of the FILE_INTERNAL_INFORMATION structure is the same as the **FileId** member of the FILE_ID_BOTH_DIR_INFORMATION and FILE_ID_FULL_DIR_INFORMATION structures.

File reference numbers, also called file IDs, are guaranteed to be unique only within a static file system. They are not guaranteed to be unique over time, because file systems are free to reuse them. Nor are they guaranteed to remain constant. For example, the FAT file system generates the file reference number for a file from the byte offset of the file's directory entry record (DIRENT) on the disk. Defragmentation can change this byte offset. Thus a FAT file reference number can change over time.

The size of the buffer passed in the **FileInformation** parameter to [**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile) or [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) must be at least ```sizeof(FILE_INTERNAL_INFORMATION)```.

This structure must be aligned on a LONGLONG (8-byte) boundary.

## See also

[**FILE_ID_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_both_dir_information)

[**FILE_ID_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_full_dir_information)

[**FILE_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_objectid_information)

[**FltQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)