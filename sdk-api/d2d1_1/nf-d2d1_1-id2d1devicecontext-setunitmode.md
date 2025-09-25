# ID2D1DeviceContext::SetUnitMode

## Description

Sets what units will be used to interpret values passed into the device context.

## Parameters

### `unitMode`

Type: **[D2D1_UNIT_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_unit_mode)**

An enumeration defining how passed-in units will be interpreted by the device context.

## Remarks

This method will affect all properties and parameters affected by [SetDpi](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-setdpi)
and [GetDpi](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-getdpi). This affects all coordinates, lengths, and other properties that are
not explicitly defined as being in another unit. For example:

* **SetUnitMode** will affect a coordinate passed
  into [ID2D1DeviceContext::DrawLine](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-drawline), and the scaling of a
  geometry passed into [ID2D1DeviceContext::FillGeometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-fillgeometry).
* **SetUnitMode** will not affect the value
  returned by [ID2D1Bitmap::GetPixelSize](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1bitmap-getpixelsize).

## See also

[D2D1_UNIT_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_unit_mode)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)