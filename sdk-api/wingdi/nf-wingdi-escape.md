# Escape function

## Description

The **Escape** function enables an application to access the system-defined device capabilities that are not available through GDI. Escape calls made by an application are translated and sent to the driver.

## Parameters

### `hdc` [in]

A handle to the device context.

### `iEscape` [in]

The escape function to be performed. This parameter must be one of the predefined escape values listed in Remarks. Use the [ExtEscape](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extescape) function if your application defines a private escape value.

### `cjIn` [in]

The number of bytes of data pointed to by the *lpvInData* parameter. This can be 0.

### `pvIn` [in]

A pointer to the input structure required for the specified escape.

### `pvOut` [out]

A pointer to the structure that receives output from this escape. This parameter should be **NULL** if no data is returned.

## Return value

If the function succeeds, the return value is greater than zero, except with the [QUERYESCSUPPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff686811(v=vs.85)) printer escape, which checks for implementation only. If the escape is not implemented, the return value is zero.

If the function fails, the return value is a system error code.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The effect of passing 0 for *cbInput* will depend on the value of *nEscape* and on the driver that is handling the escape.

Of the original printer escapes, only the following can be used.

| Escape | Description |
| --- | --- |
| QUERYESCSUPPORT | Determines whether a particular escape is implemented by the device driver. |
| PASSTHROUGH | Allows the application to send data directly to a printer. |

For information about printer escapes, see [ExtEscape](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extescape).

Use the [StartPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startpage) function to prepare the printer driver to receive data.

## See also

[AbortDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-abortdoc)

[DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties)

[EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc)

[EndPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpage)

[ExtEscape](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extescape)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[PrinterProperties](https://learn.microsoft.com/windows/desktop/printdocs/printerproperties)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[ResetDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-resetdca)

[SetAbortProc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setabortproc)

[StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca)

[StartPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startpage)