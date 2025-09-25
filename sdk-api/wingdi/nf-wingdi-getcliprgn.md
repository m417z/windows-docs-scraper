# GetClipRgn function

## Description

The **GetClipRgn** function retrieves a handle identifying the current application-defined clipping region for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `hrgn` [in]

A handle to an existing region before the function is called. After the function returns, this parameter is a handle to a copy of the current clipping region.

## Return value

If the function succeeds and there is no clipping region for the given device context, the return value is zero. If the function succeeds and there is a clipping region for the given device context, the return value is 1. If an error occurs, the return value is -1.

## Remarks

An application-defined clipping region is a clipping region identified by the [SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn) function. It is not a clipping region created when the application calls the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function.

If the function succeeds, the *hrgn* parameter is a handle to a copy of the current clipping region. Subsequent changes to this copy will not affect the current clipping region.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[Clipping Functions](https://learn.microsoft.com/windows/desktop/gdi/clipping-functions)

[Clipping Overview](https://learn.microsoft.com/windows/desktop/gdi/clipping)

[SelectClipRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectcliprgn)