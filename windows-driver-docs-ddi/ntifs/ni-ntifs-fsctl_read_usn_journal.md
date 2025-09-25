## Description

The **FSCTL_READ_USN_JOURNAL** control code retrieves the set of update sequence number (USN) change journal records between two specified USN values. See Remarks.

## Parameters

### Major code

FSCTL_READ_USN_JOURNAL

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

There are two control codes that return USN records, FSCTL_READ_USN_JOURNAL and FSCTL_ENUM_USN_DATA. Use the latter when you want a listing (enumeration) of the USN records between two USNs. Use the former when you want to select by USN.

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

* **FileObject** [in]: Parameter for [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the remote volume. This parameter is required and can't be NULL.

* **FileHandle** [in]: Parameter for [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) only. A handle for the remote volume. This parameter is required and can't be NULL.

* **FsControlCode** [in]: A control code for the operation. Use **FSCTL_READ_USN_JOURNAL** for this operation.

* **InputBuffer** [in]: Pointer to a [**READ_USN_JOURNAL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0) structure.

* **InputBufferLength** [in]: Size in bytes of the buffer at **InputBuffer**.

* **OutputBuffer** [out]: Pointer to a [**USN_RECORD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2) structure that receives the USN records.

* **OutputBufferLength** [in]: Size in bytes of the buffer at **OutputBuffer**.

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function returns the appropriate NTSTATUS error code.

## See also

[**READ_USN_JOURNAL_DATA_V0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v0)

[**READ_USN_JOURNAL_DATA_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-read_usn_journal_data_v1)

[**USN_RECORD_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v2)

[**USN_RECORD_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v3)

[**USN_RECORD_V4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v4)