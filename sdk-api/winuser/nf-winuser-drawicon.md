# DrawIcon function

## Description

Draws an icon or cursor into the specified device context.

To specify additional drawing options, use the [DrawIconEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawiconex) function.

## Parameters

### `hDC` [in]

Type: **HDC**

A handle to the device context into which the icon or cursor will be drawn.

### `X` [in]

Type: **int**

The logical x-coordinate of the upper-left corner of the icon.

### `Y` [in]

Type: **int**

The logical y-coordinate of the upper-left corner of the icon.

### `hIcon` [in]

Type: **HICON**

A handle to the icon to be drawn.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**DrawIcon** places the icon's upper-left corner at the location specified by the *X* and *Y* parameters. The location is subject to the current mapping mode of the device context.

**DrawIcon** draws the icon or cursor using the width and height specified by the system metric values for icons; for more information, see [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics).

The **DrawIcon** function calls [DrawIconEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-drawiconex) passing `DI_NORMAL|DI_DEFAULTSIZE` as flags.

#### Examples

For an example, see [Displaying an Icon](https://learn.microsoft.com/windows/desktop/menurc/using-icons).

## See also

**Conceptual**

[CreateIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createicon)

[DrawIconEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawiconex)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

**Reference**