# EndPage function

## Description

The **EndPage** function notifies the device that the application has finished writing to a page. This function is typically used to direct the device driver to advance to a new page.

## Parameters

### `hdc` [in]

A handle to the device context for the print job.

## Return value

If the function succeeds, the return value is greater than zero.

If the function fails, the return value is less than or equal to zero.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Use the [ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca) function to change the device mode, if necessary, after calling the **EndPage** function. Note that a call to **ResetDC** resets all device context attributes back to default values. Neither **EndPage** nor [StartPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startpage) resets the device context attributes. Device context attributes remain constant across subsequent pages. You do not need to re-select objects and set up the mapping mode again before printing the next page; however, doing so will produce the same results and reduce code differences between versions of Windows.

When a page in a spooled file exceeds approximately 350 MB, it may fail to print and not send an error message. For example, this can occur when printing large EMF files. The page size limit depends on many factors including the amount of virtual memory available, the amount of memory allocated by calling processes, and the amount of fragmentation in the process heap.

#### Examples

For a sample program that uses this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/desktop/printdocs/how-to--print-using-the-gdi-print-api).

## See also

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca)

[StartPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startpage)