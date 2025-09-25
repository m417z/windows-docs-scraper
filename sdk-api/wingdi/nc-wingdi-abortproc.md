# ABORTPROC callback function

## Description

The **AbortProc** function is an application-defined callback function used with the [SetAbortProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setabortproc) function. It is called when a print job is to be canceled during spooling. The **ABORTPROC** type defines a pointer to this callback function. **AbortProc** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

### `unnamedParam2`

#### - hdc [in]

A handle to the device context for the print job.

#### - iError [in]

Specifies whether an error has occurred. This parameter is zero if no error has occurred; it is SP_OUTOFDISK if Print Manager is currently out of disk space and more disk space will become available if the application waits.

## Return value

The callback function should return **TRUE** to continue the print job or **FALSE** to cancel the print job.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

If the *iError* parameter is SP_OUTOFDISK, the application need not cancel the print job. If it does not cancel the job, it must yield to Print Manager by calling the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) function.

## See also

[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[SetAbortProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setabortproc)