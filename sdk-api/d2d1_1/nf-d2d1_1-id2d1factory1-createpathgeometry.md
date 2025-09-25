# ID2D1Factory1::CreatePathGeometry

## Description

Creates an [ID2D1PathGeometry1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1pathgeometry1) object.

## Parameters

### `pathGeometry` [out]

Type: **const ****

When this method returns, contains the address of a pointer to the newly created path geometry.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)

[ID2D1PathGeometry1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1pathgeometry1)