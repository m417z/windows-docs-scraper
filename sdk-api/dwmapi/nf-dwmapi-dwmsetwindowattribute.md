# DwmSetWindowAttribute function

## Description

Sets the value of Desktop Window Manager (DWM) non-client rendering attributes for a window. For programming guidance, and code examples, see [Controlling non-client region rendering](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw#controlling-non-client-region-rendering).

## Parameters

### `hwnd` [in]

The handle to the window for which the attribute value is to be set.

### `dwAttribute` [in]

A flag describing which value to set, specified as a value of the [DWMWINDOWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/dwmapi/ne-dwmapi-dwmwindowattribute) enumeration. This parameter specifies which attribute to set, and the *pvAttribute* parameter points to an object containing the attribute value.

### `pvAttribute` [in]

A pointer to an object containing the attribute value to set. The type of the value set depends on the value of the *dwAttribute* parameter. The [**DWMWINDOWATTRIBUTE**](https://learn.microsoft.com/windows/desktop/api/Dwmapi/ne-dwmapi-dwmwindowattribute) enumeration topic indicates, in the row for each flag, what type of value you should pass a pointer to in the *pvAttribute* parameter.

### `cbAttribute` [in]

The size, in bytes, of the attribute value being set via the *pvAttribute* parameter. The type of the value set, and therefore its size in bytes, depends on the value of the *dwAttribute* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

If Desktop Composition has been disabled (Windows 7 and earlier), then this function returns **DWM_E_COMPOSITIONDISABLED**.

## Remarks

It's not valid to call this function with the *dwAttribute* parameter set to **DWMWA_NCRENDERING_ENABLED**. To enable or disable non-client rendering, you should use the **DWMWA_NCRENDERING_POLICY** attribute, and set the desired value. For more info, and a code example, see [Controlling non-client region rendering](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw#controlling-non-client-region-rendering).

## See also

* [DwmGetWindowAttribute function](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmgetwindowattribute)
* [Enable and control DWM composition](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw)