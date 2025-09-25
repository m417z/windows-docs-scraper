# IVssAsync::Cancel

## Description

The
**Cancel** method cancels an incomplete asynchronous operation.

## Return value

All calls to
**Cancel** for all
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) objects support the following status codes.

| Value | Meaning |
| --- | --- |
| **S_OK** | The asynchronous operation had been successfully canceled. |
| **VSS_S_ASYNC_CANCELLED** | The asynchronous operation had been canceled prior to calling this method. |
| **VSS_S_ASYNC_FINISHED** | The asynchronous operation had completed prior to calling this method. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

If an operation has completed unsuccessfully before
**Cancel** was called, then
**Cancel** returns the error that operation encountered.

To obtain a complete list of return values for a specific **IVssAsync::Cancel**, see the error codes of the method that returned the
[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object.

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus)