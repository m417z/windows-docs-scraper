## Description

The **FSCTL_LMR_QUERY_INFO** control code retrieves the desired information for a remote file or directory opened locally.

## Parameters

### Major code

FSCTL_LMR_QUERY_INFO

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

- **FileObject** [in]: Parameter for [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) only. A file object pointer for the remote volume. This parameter is required and can't be NULL.

- **FileHandle** [in]: Parameter for [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) only. A handle for the remote volume. This parameter is required and can't be NULL.

- **FsControlCode** [in]: A control code for the operation. Use **FSCTL_LMR_QUERY_INFO** for this operation.

- **InputBuffer** [in]: Pointer to a [**LMR_QUERY_INFO_PARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-lmr_query_info_param) structure that contains the type of information to be queried.

- **InputBufferLength** [in]: The size, in bytes, of the buffer pointed to by **InputBuffer**. This value is ```sizeof(LMR_QUERY_INFO_PARAM)```.

- **OutputBuffer** [out]: A pointer to a buffer that receives the desired information about the file or directory. The structure of the information returned in the output buffer is defined by the **Operation** specified in **InputBuffer**'s [**LMR_QUERY_INFO_PARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-lmr_query_info_param) structure.

- **OutputBufferLength** [out]: The size, in bytes, of the buffer pointed to by **OutputBuffer**.

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) returns STATUS_SUCCESS if the operation succeeds. Otherwise, the appropriate function returns the appropriate NTSTATUS error code.

## See also

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)