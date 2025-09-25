# SetAbortProc function

## Description

The **SetAbortProc** function sets the application-defined abort function that allows a print job to be canceled during spooling.

## Parameters

### `hdc` [in]

Handle to the device context for the print job.

### `proc` [in]

Pointer to the application-defined abort function. For more information about the callback function, see the [AbortProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nc-wingdi-abortproc) callback function.

## Return value

If the function succeeds, the return value is greater than zero.

If the function fails, the return value is SP_ERROR.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

#### Examples

For an example, see [How to Collect Print Job Information from the User](https://learn.microsoft.com/windows/desktop/printdocs/preparing-to-print).

## See also

[AbortDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-abortdoc)

[AbortProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nc-wingdi-abortproc)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)