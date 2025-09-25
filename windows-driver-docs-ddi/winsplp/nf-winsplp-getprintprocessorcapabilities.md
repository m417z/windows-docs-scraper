## Description

A print processor's **GetPrintProcessorCapabilities** function returns capabilities associated with a specified input data type.

## Parameters

### `pValueName` [in]

Caller-supplied pointer to a string that represents a data type that is supported by the print processor. The string pointer must be of type LPWSTR.

### `dwAttributes` [in]

Caller-supplied attributes flags. Refer to the **Attributes** member of **PRINTER_INFO_*x*** structures.

### `pData` [out]

Caller-supplied pointer to a [**PRINTPROCESSOR_CAPS_1**](https://learn.microsoft.com/windows/win32/printdocs/printprocessor-caps-1) or [**PRINTPROCESSOR_CAPS_2**](https://learn.microsoft.com/windows/win32/printdocs/printprocessor-caps-2) structure.

### `nSize` [in]

Caller-supplied value that represents the size of the buffer pointed to by *pData*.

If the value is less than sizeof(PRINTPROCESSOR_CAPS_1), this function should supply a value that is equal to sizeof(PRINTPROCESSOR_CAPS_1) or sizeof(PRINTPROCESSOR_CAPS_2), depending on which structure is supported by the print processor.

If the value is less than sizeof(PRINTPROCESSOR_CAPS_1), the winprint print processor will supply a value of sizeof(PRINTPROCESSOR_CAPS_2).

### `pcbNeeded` [out]

Caller-supplied pointer to a location to receive the minimum required size for the buffer pointed to by *pData*.

## Return value

If the operation succeeds, the function should return ERROR_SUCCESS. Otherwise, it should return a Win32 error code.

## Remarks

Print processors can optionally export a **GetPrintProcessorCapabilities** function. The function's purpose is to return a filled-in PRINTPROCESSOR_CAPS_1 or PRINTPROCESSOR_CAPS_2 structure for every input data type that the print processor supports.

The spooler calls a print processor's **GetPrintProcessorCapabilities** function when an application calls [**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata), specifying a value name with a format of PrintProcCaps_*datatype*, where *datatype* is the name of an input data type. Before calling **GetPrintProcessorCapabilities,** the spooler removes the PrintProcCaps_ prefix from the value name string.

The function should determine if the received buffer is large enough and, if it is, should fill in either the [**PRINTPROCESSOR_CAPS_1**](https://learn.microsoft.com/windows/win32/printdocs/printprocessor-caps-1) or [**PRINTPROCESSOR_CAPS_2**](https://learn.microsoft.com/windows/win32/printdocs/printprocessor-caps-2) structure and return. The value of *nSize* determines whether **PRINTPROCESSOR_CAPS_1** or **PRINTPROCESSOR_CAPS_2** will be used.

The function should always use the location pointed to by *pcbNeeded* to return the required buffer size, whether or not the actual buffer is large enough.

The specified return value becomes the return value that the spooler provides for **GetPrinterData**.