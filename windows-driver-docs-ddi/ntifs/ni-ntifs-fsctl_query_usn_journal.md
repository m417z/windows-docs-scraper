## Description

The **FSCTL_QUERY_USN_JOURNAL** control code queries for information on the current update sequence number (USN) change journal, its records, and its capacity. See Remarks.

## Parameters

### Major code

FSCTL_QUERY_USN_JOURNAL

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

* **FileObject** [in]: Parameter for [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the remote volume. This parameter is required and can't be NULL.

* **FileHandle** [in]: Parameter for [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) only. A handle for the remote volume. This parameter is required and can't be NULL.

* **FsControlCode** [in]: A control code for the operation. Use **FSCTL_QUERY_USN_JOURNAL** for this operation.

* **InputBuffer** [in]: Not used.

* **InputBufferLength** [in]: Not used.

* **OutputBuffer** [out]: Pointer to a **USN_JOURNAL_DATA** structure that receives the information about the change journal.

* **OutputBufferLength** [in]: Size in bytes of the buffer at **OutputBuffer**.

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function returns the appropriate NTSTATUS error code.

## See also

[**USN_JOURNAL_DATA_V0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_journal_data_v0)

[**USN_JOURNAL_DATA_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_journal_data_v1)

[**USN_JOURNAL_DATA_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_journal_data_v2)