# IVssAsync::Wait

## Description

The
**Wait** method waits until an incomplete asynchronous operation finishes.

## Parameters

### `dwMilliseconds` [in]

Length of time, in milliseconds, that the method will wait for an asynchronous process to return before timing out.

The default value for this argument is INFINITE.

**Windows Server 2003:** This parameter is reserved and must be INFINITE. If any other value is specified for this parameter, the call to **Wait** fails with E_INVALIDARG.

**Windows XP:** This method has no parameters.

## Return value

All calls to
**Wait** for all
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) objects support the following status codes.

| Value | Meaning |
| --- | --- |
| **S_OK** | The wait operation was successful. Call [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) to determine the final status of the asynchronous operation. |
| **E_ACCESSDENIED** | The wait operation failed because the user did not have the correct privileges. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

If an operation fails while being waited on,
**Wait** returns the error that operation encountered.

To obtain a complete list of return values for a specific **Wait**, see the error codes of the method that returned the
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object.

## Remarks

This method can succeed even if the method that returns it failed.

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus)