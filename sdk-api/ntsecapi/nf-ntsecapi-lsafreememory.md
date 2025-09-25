# LsaFreeMemory function

## Description

The **LsaFreeMemory** function frees memory allocated for an output buffer by an LSA function call. LSA functions that return variable-length output buffers always allocate the buffer on behalf of the caller. The caller must free this memory by passing the returned buffer pointer to **LsaFreeMemory** when the memory is no longer required.

## Parameters

### `Buffer` [in]

Pointer to memory buffer that was allocated by an LSA function call. If **LsaFreeMemory** is successful, this buffer is freed.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code, which can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | Memory could not be freed because it was not allocated by an LSA function call. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## See also

[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values)

[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror)