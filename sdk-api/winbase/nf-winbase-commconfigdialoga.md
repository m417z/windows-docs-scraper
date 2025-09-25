# CommConfigDialogA function

## Description

Displays a driver-supplied configuration dialog box.

## Parameters

### `lpszName` [in]

The name of the device for which a dialog box should be displayed. For example, COM1 through COM9 are serial ports and LPT1 through LPT9 are parallel ports.

### `hWnd` [in]

A handle to the window that owns the dialog box. This parameter can be any valid window handle, or it should be **NULL** if the dialog box is to have no owner.

### `lpCC` [in, out]

A pointer to a
[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig) structure. This structure contains initial settings for the dialog box before the call, and changed values after the call.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**CommConfigDialog** function requires a dynamic-link library (DLL) provided by the communications hardware vendor.

> [!NOTE]
> The winbase.h header defines CommConfigDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[COMMCONFIG](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-commconfig)

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)