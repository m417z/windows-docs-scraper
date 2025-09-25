# GetLayout function

## Description

The **GetLayout** function returns the layout of a device context (DC).

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, it returns the layout flags for the current device context.

If the function fails, it returns GDI_ERROR. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The layout specifies the order in which text and graphics are revealed in a window or device context. The default is left to right. The **GetLayout** function tells you if the default has been changed through a call to [SetLayout](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setlayout). For more information, see "Window Layout and Mirroring" in [Window Features](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[SetLayout](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setlayout)