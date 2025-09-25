# IInkDisp::ExtractWithRectangle

## Description

Cuts or copies strokes from an existing [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object and pastes them into a new **InkDisp** object, by using the known rectangle to determine which strokes to extract.

## Parameters

### `Rectangle` [in]

Specifies the [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) object which delimits the ink to extract from the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

### `extractFlags` [in, optional]

Optional. Specifies the [InkExtractFlags](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkextractflags) enumeration type, which determines whether the ink should be cut or copied from the existing [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is IEF_DEFAULT, which cuts the strokes from the existing **InkDisp** object.

### `ExtractedInk` [out, retval]

When this method returns, contains a pointer to an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object that contains the extracted collection of strokes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_SOME_STROKES_NOT_EXTRACTED** | Not all strokes were extracted. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INVALIDARG** | Invalid extraction flags. |
| **REGDB_CLASSNOTREG** | The Ink object was not registered. |

## Remarks

The new [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object retains the drawing attributes, properties, and coordinates of the original **InkDisp** object.

This method is useful for creating a new [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object without the deleted or cut strokes from the original object.

To extract strokes from a known collection of strokes, call the [ExtractStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-extractstrokes).

Only the portion of a stroke that is within the rectangle is added to the new [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

When the *extractFlags* parameter is [RemoveFromOriginal](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkextractflags) or **Default**, any strokes that cross the rectangle are split and the portion within the rectangle removed from the existing [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## See also

[ExtractStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-extractstrokes)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkExtractFlags Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkextractflags)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))