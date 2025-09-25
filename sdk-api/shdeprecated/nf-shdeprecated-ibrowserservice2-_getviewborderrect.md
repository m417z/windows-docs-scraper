# IBrowserService2::_GetViewBorderRect

## Description

Deprecated. Used with [IBrowserService2::_GetEffectiveClientArea](https://learn.microsoft.com/windows/win32/api/shdeprecated/nf-shdeprecated-ibrowserservice2-_geteffectiveclientarea) to negotiate the size and position of the browser view.

## Parameters

### `prc` [in, out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure stating the dimensions of the browser view's border.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by [IBrowserService2::GetViewRect](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-getviewrect).