# StartPage function

## Description

The **StartPage** function prepares the printer driver to accept data.

## Parameters

### `hdc` [in]

A handle to the device context for the print job.

## Return value

If the function succeeds, the return value is greater than zero.

If the function fails, the return value is less than or equal to zero.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The system disables the [ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca) function between calls to the **StartPage** and [EndPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpage) functions. This means that you cannot change the device mode except at page boundaries. After calling **EndPage**, you can call **ResetDC** to change the device mode, if necessary. Note that a call to **ResetDC** resets all device context attributes back to default values.

Neither [EndPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpage) nor **StartPage** resets the device context attributes. Device context attributes remain constant across subsequent pages. You do not need to re-select objects and set up the mapping mode again before printing the next page; however, doing so will produce the same results and reduce code differences between versions of Windows.

#### Examples

For a sample program that uses this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/desktop/printdocs/how-to--print-using-the-gdi-print-api).

## See also

[EndPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpage)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca)