## Description

**FSCTL_QUERY_FILE_REGIONS** queries a list of file regions, based on a specified usage parameter, for the file associated with the handle on which this FSCTL was invoked. This message contains an optional [**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input) data element. If no **FILE_REGION_INPUT** parameter is specified, information for the entire size of the file is returned.

## Parameters

### Major code

FSCTL_QUERY_FILE_REGIONS

### Input buffer

Pointer to a [**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input) structure that indicates the file region(s) to query.

### Input buffer length

Size of the [**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input) structure that **InputBuffer** points to, in bytes.

### Output buffer

Pointer to a [**FILE_REGION_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_output) structure in which the results of the query are returned.

### Output buffer length

Size of the buffer that **OutputBuffer** points to, in bytes.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

Reserved for system use.

## Remarks

To perform this operation, call [**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile) or [**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile) with the following parameters.

| Parameter | Description |
| --------- | ----------- |
| **Instance** | [in] For **FltFsControlFile** only. An opaque instance pointer for the caller. This parameter is required and cannot be NULL. |
| **FileObject** | [in] For **FltFsControlFile** only. A file object pointer for the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **FileHandle** | [in] For **ZwFsControlFile** only. File handle of the file or directory that is the target of this request. This parameter is required and cannot be NULL. |
| **IoStatusBlock** | [out] For **ZwFsControlFile** only. Pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure in which the final status of the request is returned. |
| **FsControlCode** | [in] Set to **FSCTL_QUERY_FILE_REGIONS**. |
| **InputBuffer** | [in/optional] Pointer to a [**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input) structure that indicates the file region(s) to query. |
| **InputBufferLength** | [in] Size of the buffer that **InputBuffer** points to, in bytes. |
| **OutputBuffer** | [out] Pointer to a [**FILE_REGION_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_output) structure in which the results of the query are returned. |
| **OutputBufferLength** | [out] Size of the buffer that **OutputBuffer** points to, in bytes. |
| **LengthReturned** | [out] Pointer to a caller-allocated variable that receives the size in bytes of the information returned in the buffer at **OutputBuffer**. |

## Return values

**FSCTL_QUERY_FILE_REGIONS** returns STATUS_SUCCESS upon successful completion; otherwise it returns an error code. On successful completion, the caller should first verify that **IoStatus.Information** is greater than or equal to **LengthReturned** before accessing the information returned in **OutputBuffer**.

## See also

[**FILE_REGION_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_input)

[**FILE_REGION_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_region_output)

[**FltFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfscontrolfile)

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)