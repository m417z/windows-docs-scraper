# IInkRecognitionAlternate::GetTextRangeFromStrokes

## Description

Retrieves the smallest range of recognized text for which the recognizer can return an alternate that contains a known [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `Strokes` [in]

The collection of strokes for which to find the containing alternate.

### `selectionStart` [in, out]

The start position of the range of recognized text within the alternate object on which this method was called that matches the smallest alternate that contains the passed-in strokes.

### `selectionLength` [in, out]

When this method returns, contains the length of the text within the range of recognized text of the smallest alternate that contains the passed-in strokes.

## Return value

If successful, returns S_OK; otherwise, returns an HRESULT error code.

## Remarks

Use this method to retrieve the text that corresponds to a specified range of strokes. For example, consider a collection of strokes, "how are you", that was drawn using nine strokes (one for each letter and three for each word). If a collection that consists of the sixth and seventh strokes is passed in, corresponding to characters "e" and "y", the text range returned matches the alternate containing "are you" and the selection start and length matches this substring.

## See also

[GetStrokesFromStrokeRanges Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-getstrokesfromstrokeranges)

[GetStrokesFromTextRange Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-getstrokesfromtextrange)

[IInkRecognition Alternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))