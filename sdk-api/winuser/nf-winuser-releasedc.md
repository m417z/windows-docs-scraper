# ReleaseDC function

## Description

The **ReleaseDC** function releases a device context (DC), freeing it for use by other applications. The effect of the **ReleaseDC** function depends on the type of DC. It frees only common and window DCs. It has no effect on class or private DCs.

## Parameters

### `hWnd` [in]

A handle to the window whose DC is to be released.

### `hDC` [in]

A handle to the DC to be released.

## Return value

The return value indicates whether the DC was released. If the DC was released, the return value is 1.

If the DC was not released, the return value is zero.

## Remarks

The application must call the **ReleaseDC** function for each call to the [GetWindowDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdc) function and for each call to the [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) function that retrieves a common DC.

An application cannot use the **ReleaseDC** function to release a DC that was created by calling the [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) function; instead, it must use the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function. **ReleaseDC** must be called from the same thread that called [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc).

#### Examples

For an example, see [Scaling an Image](https://learn.microsoft.com/windows/desktop/gdi/scaling-an-image).

## See also

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[GetWindowDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowdc)