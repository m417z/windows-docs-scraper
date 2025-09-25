# ID2D1DeviceContext2::CreateInkStyle

## Description

Creates a new [ID2D1InkStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1inkstyle) object, for use with ink
rendering methods such as [DrawInk](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1devicecontext2-drawink).

## Parameters

### `inkStyleProperties` [ref]

Type: **const [D2D1_INK_STYLE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_style_properties)**

The properties of the ink style to be created.

### `inkStyle` [out]

Type: **[ID2D1InkStyle](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1inkstyle)****

When this method returns, contains the address of a pointer to a new ink style object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)