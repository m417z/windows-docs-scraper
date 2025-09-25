# IInkDisp::CreateStrokes

## Description

Creates a new [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection from existing [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects.

## Parameters

### `StrokeIds` [in, optional]

Optional. Specifies an array of stroke IDs that exist in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The strokes with these IDs are added to a new [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection. The default value is **NULL**.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Strokes` [out, retval]

When this method returns, contains a pointer to a new [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid VARIANT type (only VT_ARRAY | VT_I4 supported). |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_OUTOFMEMORY** | Cannot allocate memory to create the new Strokes collection. |
| **TPC_E_INVALID_STROKE** | Stroke IDs that do not exist were passed to the method. |

## Remarks

If the *ids* parameter is **NULL** or an empty array, then an empty [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection is created.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))