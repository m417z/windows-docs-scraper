# ITfLangBarItemBitmap::OnClick

## Description

Not currently used.

## Parameters

### `click` [in]

Contains one of the [TfLBIClick](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbiclick) values that indicate which mouse button was used to click the bitmap.

### `pt` [in]

Pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the position of the mouse cursor, in screen coordinates, at the time of the click event.

### `prcArea` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the bounding rectangle, in screen coordinates, of the bitmap.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## See also

[ITfLangBarItemBitmap](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritembitmap)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[TfLBIClick](https://learn.microsoft.com/windows/win32/api/ctfutb/ne-ctfutb-tflbiclick)