# ID2D1SimplifiedGeometrySink::SetFillMode

## Description

Specifies the method used to determine which points are inside the geometry described by this geometry sink and which points are outside.

## Parameters

### `fillMode`

Type: **[D2D1_FILL_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_fill_mode)**

The method used to determine whether a given point is part of the geometry.

## Remarks

The fill mode defaults to D2D1_FILL_MODE_ALTERNATE. To set the fill mode, call **SetFillMode** before the first call to [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure). Not doing will put the geometry sink in an error state.

## See also

[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)