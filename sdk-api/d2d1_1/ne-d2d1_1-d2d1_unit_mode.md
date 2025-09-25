# D2D1_UNIT_MODE enumeration

## Description

Specifies how units in Direct2D will be interpreted.

## Constants

### `D2D1_UNIT_MODE_DIPS:0`

Units will be interpreted as device-independent pixels (1/96").

### `D2D1_UNIT_MODE_PIXELS:1`

Units will be interpreted as pixels.

### `D2D1_UNIT_MODE_FORCE_DWORD:0xffffffff`

## Remarks

Setting the unit mode to **D2D1_UNIT_MODE_PIXELS** is similar to setting the [ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext) dots per inch (dpi) to 96. However, Direct2D still checks the dpi to determine the threshold for enabling vertical antialiasing for text, and when the unit mode is restored, the dpi will be remembered.

## See also

[ID2D1DeviceContext::GetUnitMode](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-getunitmode)

[ID2D1DeviceContext::SetUnitMode](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-setunitmode)