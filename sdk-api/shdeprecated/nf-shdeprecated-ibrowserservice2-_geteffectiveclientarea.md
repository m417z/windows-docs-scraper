# IBrowserService2::_GetEffectiveClientArea

## Description

Deprecated. Used with [IBrowserService2::_GetViewBorderRect](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_getviewborderrect) to negotiate the dimensions of the browser view.

## Parameters

### `lprectBorder` [in, out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure indicating the dimensions of the available client area.

### `hmon` [in]

Type: **HMONITOR**

The handle of the monitor on which the view is displayed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[HMONITOR and the Device Context](https://learn.microsoft.com/windows/desktop/gdi/hmonitor-and-the-device-context)

[IBrowserService2](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nn-shdeprecated-ibrowserservice2)