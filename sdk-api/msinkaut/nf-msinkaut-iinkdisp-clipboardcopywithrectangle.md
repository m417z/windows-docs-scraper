# IInkDisp::ClipboardCopyWithRectangle

## Description

Copies the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects that are contained within the known rectangle to the Clipboard.

## Parameters

### `Rectangle` [in]

Specifies the rectangle that contains the strokes to copy to the Clipboard.

### `ClipboardFormats` [in, optional]

Optional. Specifies the [InkClipboardFormats](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardformats) enumeration value of the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is **ICF_Default**.

### `ClipboardModes` [in, optional]

Optional. Specifies the [InkClipboardModes Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes) value of the [InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The default value is **ICB_Default**.

### `DataObject` [out, retval]

When this method returns, contains a pointer to the newly create data object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

If the rectangle clips strokes, those strokes are clipped in the copied data.

It may be useful to copy an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object to the Clipboard when you only want to copy the properties of the **InkDisp** object. To copy an **InkDisp** object to the Clipboard, call the [ClipboardCopy](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopy) method with the *strokes* parameter set to **NULL**.

**Caution** To avoid potential memory leaks as a result of using the [ICB_DelayedCopy](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes) flag, you must call the [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard) or [OleSetClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetclipboard) method. This must be done before the application exits if the last call to the **ClipboardCopyWithRectangle** method used the **ICB_DelayedCopy** flag.

When **ClipboardCopyWithRectangle** is used in [ICB_Cut](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes) mode, a stroke that gets split into two or more strokes is deleted and new strokes are added in its place.

In addition, the [InkAdded](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkadded) and [InkDeleted](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkdeleted) events are generated based on the indices of the strokes. For example, if the strokes at indices 0,1,3,5, and 6 are to be deleted, two events will be generated; one for strokes with indices 0123 and one for strokes with indices 5 and 6. That is, one event for each contiguous set.

This also applies to [InkAdded](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkadded) events. An internal algorithm determines the indices of the newly added strokes in the stroke collection and this has an impact on how the **InkAdded** events are fired as described above.

If the strokes count is queried within the event handler, the result is the total number of strokes added by the whole operation including the strokes that have not yet generated events.

## See also

[ClipboardCopy Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopy)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkClipboardFormats Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardformats)

[InkClipboardModes Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkclipboardmodes)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))