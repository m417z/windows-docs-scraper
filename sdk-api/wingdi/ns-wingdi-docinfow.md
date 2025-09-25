# DOCINFOW structure

## Description

The **DOCINFO** structure contains the input and output file names and other information used by the [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) function.

## Members

### `cbSize`

The size, in bytes, of the structure.

### `lpszDocName`

Pointer to a null-terminated string that specifies the name of the document.

### `lpszOutput`

Pointer to a null-terminated string that specifies the name of an output file. If this pointer is **NULL**, the output will be sent to the device identified by the device context handle that was passed to the [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) function.

### `lpszDatatype`

Pointer to a null-terminated string that specifies the type of data used to record the print job. The legal values for this member can be found by calling [EnumPrintProcessorDatatypes](https://learn.microsoft.com/windows/desktop/printdocs/enumprintprocessordatatypes) and can include such values as raw, emf, or XPS_PASS. This member can be **NULL**. Note that the requested data type might be ignored.

### `fwType`

Specifies additional information about the print job. This member must be zero or one of the following values.

| Value | Meaning |
| --- | --- |
| DI_APPBANDING | Applications that use banding should set this flag for optimal performance during printing. |
| DI_ROPS_READ_DESTINATION | The application will use raster operations that involve reading from the destination surface. |

## See also

[Print Spooler API Structures](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-structures)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca)

## Remarks

> [!NOTE]
> The wingdi.h header defines DOCINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).