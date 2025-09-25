# StartDocA function

## Description

The **StartDoc** function starts a print job.

## Parameters

### `hdc` [in]

A handle to the device context for the print job.

### `lpdi` [in]

A pointer to a [DOCINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-docinfoa) structure containing the name of the document file and the name of the output file.

## Return value

If the function succeeds, the return value is greater than zero. This value is the print job identifier for the document.

If the function fails, the return value is less than or equal to zero.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Applications should call the **StartDoc** function immediately before beginning a print job. Using this function ensures that multipage documents are not interspersed with other print jobs.

Applications can use the value returned by **StartDoc** to retrieve or set the priority of a print job. Call the [GetJob](https://learn.microsoft.com/windows/desktop/printdocs/getjob) or [SetJob](https://learn.microsoft.com/windows/desktop/printdocs/setjob) function and supply this value as one of the required arguments.

#### Examples

For a sample program that uses this function, see [How To: Print Using the GDI Print API](https://learn.microsoft.com/windows/desktop/printdocs/how-to--print-using-the-gdi-print-api).

> [!NOTE]
> The wingdi.h header defines StartDoc as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DOCINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-docinfoa)

[EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc)

[GetJob](https://learn.microsoft.com/windows/desktop/printdocs/getjob)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[SetJob](https://learn.microsoft.com/windows/desktop/printdocs/setjob)