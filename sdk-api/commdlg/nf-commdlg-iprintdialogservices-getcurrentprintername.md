# IPrintDialogServices::GetCurrentPrinterName

## Description

Retrieves the name of the currently selected printer, for use with [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)).

## Parameters

### `pPrinterName`

Type: **LPTSTR**

The name of the currently selected printer.

### `pcchSize`

Type: **UINT***

On input, the variable specifies the size, in characters, of the buffer pointed to by the *lpPrinterName* parameter. On output, the variable contains the number of bytes (ANSI) or characters (Unicode), including the terminating null character, written to the buffer.

If the size is zero on input, the function returns the required buffer size (in bytes or characters) in *pcchSize* and does not use the *lpPrinterName* buffer.

## Return value

Type: **HRESULT**

If the method is successful, the return value is **S_OK**. If no printer is currently selected, the return value is **S_OK**, the value returned in *pcchSize* is zero, and the *lpPrinterName* buffer is unchanged.

If an error occurs, the return value is a COM error code. For more information, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices)

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**