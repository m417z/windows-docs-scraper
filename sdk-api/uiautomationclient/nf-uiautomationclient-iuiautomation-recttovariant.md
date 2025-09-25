# IUIAutomation::RectToVariant

## Description

Creates a [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) that contains the coordinates of a rectangle.

## Parameters

### `rc` [in]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a structure that contains the coordinates of the rectangle.

### `var` [out, retval]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)***

Receives the coordinates of the rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) has a data type of VT_ARRAY | VT_R8.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)

[IUIAutomation::VariantToRect](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-varianttorect)