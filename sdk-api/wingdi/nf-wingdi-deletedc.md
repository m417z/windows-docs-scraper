# DeleteDC function

## Description

The **DeleteDC** function deletes the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application must not delete a DC whose handle was obtained by calling the [GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc) function. Instead, it must call the [ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc) function to free the DC.

#### Examples

For an example, see [Retrieving the Capabilities of a Printer](https://learn.microsoft.com/windows/desktop/gdi/retrieving-the-capabilities-of-a-printer).

## See also

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[ReleaseDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-releasedc)