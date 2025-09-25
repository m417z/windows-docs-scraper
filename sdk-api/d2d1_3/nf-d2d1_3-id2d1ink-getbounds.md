# ID2D1Ink::GetBounds

## Description

Retrieve the bounds of the geometry, with an optional applied transform.

## Parameters

### `inkStyle` [in, optional]

Type: **[ID2D1InkStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1inkstyle)***

The ink style to be used in determining the bounds of this ink object.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The world transform to be used in determining the bounds of this ink object.

### `bounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

When this method returns, contains the bounds of this ink object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)