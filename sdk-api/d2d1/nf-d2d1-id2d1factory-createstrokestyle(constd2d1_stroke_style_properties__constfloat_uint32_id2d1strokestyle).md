# ID2D1Factory::CreateStrokeStyle(const D2D1_STROKE_STYLE_PROPERTIES &,const FLOAT,UINT32,ID2D1StrokeStyle)

## Description

Creates an [ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle) that describes start cap, dash pattern, and other features of a stroke.

## Parameters

### `strokeStyleProperties` [ref]

Type: **const [D2D1_STROKE_STYLE_PROPERTIES](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_stroke_style_properties)**

A structure that describes the stroke's line cap, dash offset, and other details of a stroke.

### `dashes` [in, optional]

Type: **const FLOAT***

An array whose elements are set to the length of each dash and space in the dash pattern. The first element sets the length of a dash, the second element sets the length of a space, the third element sets the length of a dash, and so on. The length of each dash and space in the dash pattern is the product of the element value in the array and the stroke width.

### `dashesCount`

Type: **UINT**

The number of elements in the *dashes* array.

### `strokeStyle` [out]

Type: **[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)****

When this method returns, contains the address of the pointer to the stroke style created by this method.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) error code.

## See also

[ID2D1Factory](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1factory)