# ID2D1Ink::StreamAsGeometry(ID2D1InkStyle,const D2D1_MATRIX_3X2_F,ID2D1SimplifiedGeometrySink)

## Description

Retrieves a geometric representation of this ink object.

## Parameters

### `inkStyle` [in, optional]

Type: **[ID2D1InkStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1inkstyle)***

The ink style to be used in determining the geometric representation.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The world transform to be used in determining the geometric representation.

### `geometrySink` [in]

Type: **[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)***

The geometry sink to which the geometry representation will be streamed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)