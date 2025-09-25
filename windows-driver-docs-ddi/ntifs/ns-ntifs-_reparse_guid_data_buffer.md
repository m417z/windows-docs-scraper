# REPARSE_GUID_DATA_BUFFER structure

## Description

The REPARSE_GUID_DATA_BUFFER structure contains reparse point data for a reparse point.

## Members

### `ReparseTag`

Reparse point tag that uniquely identifies the owner of the reparse point. (See the following **Remarks** section.)

### `ReparseDataLength`

Size, in bytes, of the reparse data in the **DataBuffer** member.

### `Reserved`

Reserved; do not use.

### `ReparseGuid`

GUID that uniquely identifies the owner of the reparse point. (See the following **Remarks** section.)

### `GenericReparseBuffer`

### `GenericReparseBuffer.DataBuffer`

User-defined data for the reparse point. The format of this data is defined by the owner of the reparse point.

## Remarks

The REPARSE_GUID_DATA_BUFFER structure is used by all third-party file systems, filters, and minifilters, as well as some Microsoft file systems, filters, and minifilters to store data for a reparse point. Each reparse point contains one REPARSE_GUID_DATA_BUFFER structure.

Microsoft reparse points can use the [REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer) structure instead of the REPARSE_GUID_DATA_BUFFER structure. However, third-party reparse points are required to use the REPARSE_GUID_DATA_BUFFER structure.

Reparse point tags are [assigned to third parties by Microsoft](https://learn.microsoft.com/windows-hardware/drivers/ifs/reparse-point-tag-request). You may request more than one reparse point for use with a file system, file system filter driver, or minifilter driver.

Reparse point GUIDs are not assigned by Microsoft. However, you must choose one GUID to use with your assigned reparse point tag, and you must always use this GUID with the tag. To generate a GUID, you can use GUIDGen (*Guidgen.exe*), a tool that is included in the Microsoft Windows SDK.

Minifilters can set or delete a reparse point by calling [FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile) or [FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile). Minifilters can retrieve a reparse point by using the [FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point) control code. This code can be sent to the file system by calling [FltFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile).

File systems and filter drivers can retrieve, set, or delete a reparse point by using the [FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point), [FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point), and [FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point) control codes. These codes can be sent to the file system by calling [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile).

For more information about reparse points and reparse point tags, see the Windows SDK documentation.

## See also

[FILE_REPARSE_POINT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_reparse_point_information)

[FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)

[FSCTL_DELETE_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-delete-reparse-point)

[FSCTL_GET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-reparse-point)

[FSCTL_SET_REPARSE_POINT](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-reparse-point)

[FltFsControlFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[FltTagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfile)

[FltTagFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flttagfileex)

[FltUntagFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuntagfile)

[IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-file-system-control)

[IsReparseTagMicrosoft](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagmicrosoft)

[IsReparseTagNameSurrogate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-isreparsetagnamesurrogate)

[REPARSE_DATA_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer)

[REPARSE_DATA_BUFFER_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_reparse_data_buffer_ex)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)