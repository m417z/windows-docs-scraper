# FltRequestSecurityInfoOnCreateCompletion function

## Description

A minifilter calls **FltRequestSecurityInfoOnCreateCompletion** during file pre-create to request that the file system stores file security information for retrieval during post create.

## Parameters

### `Filter`

Opaque filter pointer that uniquely identifies the minifilter driver.

### `Data`

Pointer to the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data representing the I/O create operation.

### `SecurityInformation`

[**SECURITY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information) value specifying the information to be set as a combination of one or more of the following.

| Value | Meaning |
| ----- | ------- |
| OWNER_SECURITY_INFORMATION | Indicates the owner identifier of the object is to be set. Requires WRITE_OWNER access. |
| GROUP_SECURITY_INFORMATION | Indicates the primary group identifier of the object is to be set. Requires WRITE_OWNER access. |
| DACL_SECURITY_INFORMATION | Indicates the discretionary access control list (DACL) of the object is to be set. Requires WRITE_DAC access. |
| SACL_SECURITY_INFORMATION | Indicates the system ACL (SACL) of the object is to be set. Requires ACCESS_SYSTEM_SECURITY access. |

## Return value

**FltRequestSecurityInfoOnCreateCompletion** can return one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | The file system successfully stored the requested file security information. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltRequestSecurityInfoOnCreateCompletion** was unable to allocate sufficient memory in which to store the requested file information. |
| **STATUS_INVALID_PARAMETER_2** | The provided callback data object was not an IRP-based create operation. |

## Remarks

The minifilter can retrieve the file information by calling [**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex) or [**FltRetrieveFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletion) during post create. A minifilter's performance is typically better when it requests and retrieves file information in this manner, rather than querying file information at a later time.

## See also

[**FltRetrieveFileInfoOnCreateCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletion)

[**FltRetrieveFileInfoOnCreateCompletionEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrievefileinfooncreatecompletionex)