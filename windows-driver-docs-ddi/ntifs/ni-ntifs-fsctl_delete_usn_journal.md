## Description

The **FSCTL_DELETE_USN_JOURNAL** control code deletes the update sequence number (USN) change journal on a volume, or waits for notification of change journal deletion. See Remarks.

## Parameters

### Major code

FSCTL_DELETE_USN_JOURNAL

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

**FSCTL_DELETE_USN_JOURNAL** can be used to:

* Delete a change journal. The NTFS file system starts a deletion operation and returns immediately to the calling process, unless the **USN_DELETE_FLAG_NOTIFY** flag is set in the **DeleteFlags** member of [**DELETE_USN_JOURNAL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-delete_usn_journal_data).

 If the **USN_DELETE_FLAG_NOTIFY** and **USN_DELETE_FLAG_DELETE** flags are both set, a call to **FSCTL_DELETE_USN_JOURNAL** begins the deletion process. Then the call either blocks the calling thread and waits for the deletion (on a synchronous or non-overlapped call), or sets up event notification by using an I/O completion port or other mechanism, and returns (on an asynchronous or overlapped call).

* Receive notification that a change journal deletion is complete, by setting only **USN_DELETE_FLAG_NOTIFY**. If you do so, the **FSCTL_DELETE_USN_JOURNAL** operation either waits until the deletion completes before returning (on a synchronous or non-overlapped call), or sets up event notification by using an I/O completion port or other mechanism (on an asynchronous or overlapped call).

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

* **FileObject** [in]: Parameter for [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the remote volume. This parameter is required and can't be NULL.

* **FileHandle** [in]: Parameter for [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) only. A handle for the remote volume. This parameter is required and can't be NULL.

* **FsControlCode** [in]: A control code for the operation. Use **FSCTL_CREATE_USN_JOURNAL** for this operation.

* **InputBuffer** [in]: Pointer to a [**DELETE_USN_JOURNAL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-delete_usn_journal_data) structure that contains the parameters for the operation.

* **InputBufferLength** [in]: The size, in bytes, of the input buffer.

* **OutputBuffer** [out]: Not used.

* **OutputBufferLength** [in]: Not used.

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function returns the appropriate NTSTATUS error code.

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**FSCTL_CREATE_USN_JOURNAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_create_usn_journal)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)