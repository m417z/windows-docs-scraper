# FltClose function

## Description

**FltClose** closes a file handle that was opened by [FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile) or [FltCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex).

## Parameters

### `FileHandle` [in]

Handle created by a successful call to [FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile) or [FltCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex).

## Return value

**FltClose** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_HANDLE** | *FileHandle* was not a valid file handle. This is an error code. |

## Remarks

**FltClose** is only for closing file handles opened by [FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile) or [FltCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex). It should not be used to close arbitrary handles.

## See also

[FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile)

[FltCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)