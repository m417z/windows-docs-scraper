# AbortDoc function

## Description

The **AbortDoc** function stops the current print job and erases everything drawn since the last call to the [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) function.

## Parameters

### `hdc` [in]

Handle to the device context for the print job.

## Return value

If the function succeeds, the return value is greater than zero.

If the function fails, the return value is SP_ERROR.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Applications should call the **AbortDoc** function to stop a print job if an error occurs, or to stop a print job after the user cancels that job. To end a successful print job, an application should call the [EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc) function.

If Print Manager was used to start the print job, calling **AbortDoc** erases the entire spool job, so that the printer receives nothing. If Print Manager was not used to start the print job, the data may already have been sent to the printer. In this case, the printer driver resets the printer (when possible) and ends the print job.

## See also

[EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[SetAbortProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setabortproc)

[StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca)