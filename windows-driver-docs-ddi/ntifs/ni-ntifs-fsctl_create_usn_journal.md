## Description

The **FSCTL_CREATE_USN_JOURNAL** control code creates an update sequence number (USN) change journal stream on a target volume, or modifies an existing change journal stream. See Remarks.

## Parameters

### Major code

FSCTL_CREATE_USN_JOURNAL

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

**FSCTL_CREATE_USN_JOURNAL** can be used to:

* Create a new change journal stream for a volume. After the creation of the stream, the NTFS file system maintains a change journal for that volume.

* Modify an existing change journal stream. If a change journal stream already exists, **FSCTL_CREATE_USN_JOURNAL** sets it to the characteristics provided in the [**CREATE_USN_JOURNAL_DATA**] structure. The change journal stream eventually gets larger or is trimmed to the new size limit that **CREATE_USN_JOURNAL_DATA** imposes.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

* **FileObject** [in]: Parameter for [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the remote volume. This parameter is required and can't be NULL.

* **FileHandle** [in]: Parameter for [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) only. A handle for the remote volume. This parameter is required and can't be NULL.

* **FsControlCode** [in]: A control code for the operation. Use **FSCTL_CREATE_USN_JOURNAL** for this operation.

* **InputBuffer** [in]: Pointer to a [**CREATE_USN_JOURNAL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-create_usn_journal_data) structure that contains the parameters for the operation.

* **InputBufferLength** [in]: The size, in bytes, of the input buffer.

* **OutputBuffer** [out]: Not used.

* **OutputBufferLength** [in]: Not used.

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function returns the appropriate NTSTATUS error code.

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FSCTL_DELETE_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_delete_usn_journal)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)