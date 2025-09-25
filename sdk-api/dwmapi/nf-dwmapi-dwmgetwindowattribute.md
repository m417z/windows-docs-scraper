# DwmGetWindowAttribute function

## Description

Retrieves the current value of a specified Desktop Window Manager (DWM) attribute applied to a window. For programming guidance, and code examples, see [Controlling non-client region rendering](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw#controlling-non-client-region-rendering).

## Parameters

### `hwnd` [in]

The handle to the window from which the attribute value is to be retrieved.

### `dwAttribute` [in]

A flag describing which value to retrieve, specified as a value of the [DWMWINDOWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/dwmapi/ne-dwmapi-dwmwindowattribute) enumeration. This parameter specifies which attribute to retrieve, and the *pvAttribute* parameter points to an object into which the attribute value is retrieved.

### `pvAttribute` [out]

A pointer to a value which, when this function returns successfully, receives the current value of the attribute. The type of the retrieved value depends on the value of the *dwAttribute* parameter. The [**DWMWINDOWATTRIBUTE**](https://learn.microsoft.com/windows/desktop/api/Dwmapi/ne-dwmapi-dwmwindowattribute) enumeration topic indicates, in the row for each flag, what type of value you should pass a pointer to in the *pvAttribute* parameter.

### `cbAttribute` [in]

The size, in bytes, of the attribute value being received via the *pvAttribute* parameter. The type of the retrieved value, and therefore its size in bytes, depends on the value of the *dwAttribute* parameter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## See also

* [DwmSetWindowAttribute function](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute)
* [Enable and control DWM composition](https://learn.microsoft.com/windows/desktop/dwm/composition-ovw)