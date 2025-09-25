# OleTranslateColor function

## Description

Converts an **OLE_COLOR** type to a **COLORREF**.

## Parameters

### `clr` [in]

The OLE color to be converted into a **COLORREF**.

### `hpal` [in]

Palette used as a basis for the conversion.

### `lpcolorref` [out]

Pointer to the caller's variable that receives the converted **COLORREF** result. This parameter can be **NULL**, indicating that the caller wants only to verify that a converted color exists.

## Return value

This function supports the standard return values E_INVALIDARG and E_UNEXPECTED, as well as the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The color was translated successfully. |

## Remarks

The following table describes the color conversion.

| OLE_COLOR | hPal | COLORREF |
| --- | --- | --- |
| invalid |  | Undefined (E_INVALIDARG) |
| 0x800000xx, xx is not a valid [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) index |  | Undefined (E_INVALIDARG) |
|  | invalid | Undefined (E_INVALIDARG) |
| 0x0100iiii, iiii is not a valid palette index | valid palette | Undefined (E_INVALIDARG) |
| 0x800000xx, xx is a valid [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) index | **NULL** | 0x00bbggrr |
| 0x0100iiii, iiii is a valid palette index | **NULL** | 0x0100iiii |
| 0x02bbggrr (palette relative) | **NULL** | 0x02bbggrr |
| 0x00bbggrr | **NULL** | 0x00bbggrr |
| 0x800000xx, xx is a valid [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) index | valid palette | 0x00bbggrr |
| 0x0100iiii, iiii is a valid palette index in hPal | valid palette | 0x0100iiii |
| 0x02bbggrr (palette relative) | valid palette | 0x02bbggrr |
| 0x00bbggrr | valid palette | 0x02bbggrr |