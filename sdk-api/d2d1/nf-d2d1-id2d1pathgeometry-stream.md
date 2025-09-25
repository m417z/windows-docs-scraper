# ID2D1PathGeometry::Stream

## Description

Copies the contents of the path geometry to the specified [ID2D1GeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrysink).

## Parameters

### `geometrySink` [in]

Type: **[ID2D1GeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1geometrysink)***

The sink to which the path geometry's contents are copied. Modifying this sink does not change the contents of this path geometry.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1PathGeometry](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1pathgeometry)