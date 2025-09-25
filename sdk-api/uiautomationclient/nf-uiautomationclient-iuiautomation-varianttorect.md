# IUIAutomation::VariantToRect

## Description

Converts a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) containing rectangle coordinates to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect).

## Parameters

### `var` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)**

The coordinates of a rectangle.

### `rc` [out, retval]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Receives the converted rectangle coordinates.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.