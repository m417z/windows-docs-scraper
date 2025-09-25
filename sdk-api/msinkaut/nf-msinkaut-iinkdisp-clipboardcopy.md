# IInkDisp::ClipboardCopy

## Description

Copies the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection to the Clipboard.

## Parameters

### `strokes` [in, optional]

Optional. Specifies the strokes to copy. If the strokes parameter is **NULL**, the **ClipboardCopy** method copies the entire [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is **NULL**.

### `ClipboardFormats` [in, optional]

Optional. Specifies the [InkClipboardFormats](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardformats) enumeration value of the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is **ICF_Default**.

### `ClipboardModes` [in, optional]

Optional. Specifies the [InkClipboardModes](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes) enumeration value of the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is **ICB_Default**.

### `DataObject` [out, retval]

When this method returns, contains a pointer to the newly create data object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_MISMATCHED_INK_OBJECT** | The strokes parameter is associated with a different Ink object. |

## Remarks

This method copies all properties of the stroke, including recognition results. Setting the *strokes* parameter to **NULL** copies the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object to the Clipboard, including the [CustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-get_customstrokes) property, and recognition results for strokes in the **InkDisp** object's [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection are maintained.

If an empty [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection is passed, the method returns **NULL** and the contents of the Clipboard are not modified.

**Note** [OleInitialize(NULL)](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) must be called before the clipboard APIs can work.

**Caution** To avoid potential memory leaks as a result of using the [ICB_DelayedCopy](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes) flag, you must call the [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) or [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) method. This must be done before the application exits if the last call to the **ClipboardCopy** method used the **ICB_DelayedCopy** flag.

## See also

[ClipboardCopyWithRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopywithrectangle)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkClipboardFormats Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardformats)

[InkClipboardModes Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))