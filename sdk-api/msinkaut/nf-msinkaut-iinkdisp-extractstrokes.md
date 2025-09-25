# IInkDisp::ExtractStrokes

## Description

Specifies the strokes to extract from an [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) and cut or copy into a new **InkDisp Class**, by using the known collection of strokes to determine which strokes to extract.

## Parameters

### `Strokes` [in, optional]

Optional. Specifies the collection of strokes to extract. The default value is 0, which specifies that all strokes are extracted.

### `ExtractFlags` [in, optional]

Optional. Specifies the [InkExtractFlags Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkextractflags) type, which specifies whether the ink is cut or copied into the new Ink object. The default value is IEF_DEFAULT, which cuts the strokes.

### `ExtractedInk` [out, retval]

When this method returns, contains a pointer to a new [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object that contains the extracted collection of cut or copied strokes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_MISMATCHED_INK_OBJECT** | The [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object of the [InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection must match the known **InkDisp Class**. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_SOME_STROKES_NOT_EXTRACTED** | Not all strokes were extracted. |
| **E_OUTOFMEMORY** | Cannot allocate memory that is used to perform the operation. |
| **E_INVALIDARG** | Invalid extraction flags. |
| **REGDB_CLASSNOTREG** | The [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object class is not registered. |

## See also

[ExtractWithRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-extractwithrectangle)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)