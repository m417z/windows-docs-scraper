# IInkRecognitionAlternate::GetStrokesFromStrokeRanges

## Description

Retrieves the smallest [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection that contains a known input InkStrokes collection and for which the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object can provide alternates.

## Parameters

### `Strokes` [in]

The collection of stroke objects to use to find the smallest stroke collection of the recognition result alternate that contains this collection.

### `GetStrokesFromStrokeRanges` [out, retval]

When this method returns, contains a pointer to the smallest collection of strokes that contains a known input collection of strokes and for which the recognizer can provide alternates.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INK_MISMATCHED_INK_OBJECT** | The strokes parameter is associated with a different Ink object. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The returned collection may match the input collection, or it may be larger if the input collection matches only part of the smallest recognition result that includes all of the input strokes.

This method is most useful for single-click word selection. For example, to return the strokes that make up the word you clicked, you can click a stroke, call the [HitTest](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-hittestcircle) method of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object to retrieve the stroke that was clicked, and then call **GetStrokesFromStrokeRanges**.

The stroke ranges are valid until the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object is modified.

## See also

[GetStrokesFromTextRange Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-getstrokesfromtextrange)

[GetTextRangeFromStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-gettextrangefromstrokes)

[IInkRecognition Alternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))