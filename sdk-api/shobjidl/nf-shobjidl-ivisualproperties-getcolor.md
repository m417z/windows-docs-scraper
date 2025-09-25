# IVisualProperties::GetColor

## Description

Gets the color, as specified.

## Parameters

### `vpcf` [in]

Type: **[VPCOLORFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-vpcolorflags)**

The color flags. See [VPCOLORFLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl/ne-shobjidl-vpcolorflags)

### `pcr` [out]

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)***

A pointer to a value of type [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.