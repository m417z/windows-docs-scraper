# FSCTL_INVALIDATE_VOLUMES control code

The **FSCTL_INVALIDATE_VOLUMES** control code finds and removes all the volumes mounted on the device represented by the specified file object or handle.

To perform this operation, minifilter drivers call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile), and file systems, redirectors, and legacy file system filter drivers call [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)), using the following parameters.

## Parameters

- **FileObject** [in]: Handle to the device. To obtain a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function.

- **FileHandle** [in]: Handle to the device. To obtain a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function.

- **FsControlCode** [in]: Control code for the operation. Use **FSCTL_INVALIDATE_VOLUMES** for this operation.

- **InputBuffer** [in]: Not used with this operation; set to **NULL**.

- **InputBufferLength** [in]: Not used with this operation; set to zero.

- **OutputBuffer** [out]: Not used with this operation; set to **NULL**.

- **OutputBufferLength** [out]: Not used with this operation; set to zero.

## Status block

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) and [**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85)) return STATUS_SUCCESS if the operation succeeds or an appropriate NTSTATUS value.

## Remarks

FSCTL_INVALIDATE_VOLUMES is sent to the file system's control (that is, named) device object, not to a volume device object. For more information about Control Device Objects, see [Creating the Control Device Object](https://learn.microsoft.com/windows-hardware/drivers/ifs/creating-the-control-device-object).

FAT and NTFS file systems handle surprise removal by responding to IRP_MJ_PNP/IRP_MN_SURPRISE_REMOVAL.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h*) |

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/previous-versions/ff566462(v=vs.85))