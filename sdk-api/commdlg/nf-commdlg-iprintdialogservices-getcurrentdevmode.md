# IPrintDialogServices::GetCurrentDevMode

## Description

Fills a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure with information about the currently selected printer for use with [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)).

## Parameters

### `pDevMode`

Type: **LPDEVMODE**

A pointer to a buffer that receives a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure containing information about the currently selected printer.

### `pcbSize`

Type: **UINT***

On input, the variable specifies the size, in bytes, of the buffer pointed to by the *lpDevMode* parameter. On output, the variable contains the number of bytes written to *lpDevMode*.

If the size is zero on input, the function returns the required buffer size (in bytes) in *pcbSize* and does not use the *lpDevMode* buffer.

## Return value

Type: **HRESULT**

If the method is successful, the return value is **S_OK**. If no printer is currently selected, the return value is **S_OK**, the value returned in *pcbSize* is zero, and the *lpDevMode* buffer is unchanged.

If an error occurs, the return value is a COM error code. For more information, see [Error Handling](https://learn.microsoft.com/windows/desktop/SetupApi/error-handling).

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[IPrintDialogServices](https://learn.microsoft.com/windows/desktop/api/commdlg/nn-commdlg-iprintdialogservices)

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**