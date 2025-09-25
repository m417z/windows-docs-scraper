# ID2D1Factory1::CreateDrawingStateBlock(ID2D1DrawingStateBlock1)

## Description

Creates a new drawing state block, this can be used in subsequent
SaveDrawingState and RestoreDrawingState operations on the render target.

## Parameters

### `drawingStateBlock` [out]

Type: **[ID2D1DrawingStateBlock1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1drawingstateblock1)****

The address of the newly created drawing state block.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)