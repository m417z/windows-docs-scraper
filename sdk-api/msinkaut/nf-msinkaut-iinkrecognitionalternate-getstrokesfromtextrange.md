# IInkRecognitionAlternate::GetStrokesFromTextRange

## Description

Retrieves the collection that corresponds to the smallest set of recognition segments that contains a specified character range within the alternate.

## Parameters

### `selectionStart` [in, out]

The start of the character range within this alternate. The character at the *selectionStart* position is included in the range of recognized text. This parameter is adjusted to the beginning of the smallest recognized set of one or more segments that includes the input selection. The *selectionStart* parameter is a zero-based index into the characters in the recognition alternate's text.

### `selectionLength` [in, out]

The length of the character range within the alternate. This parameter must be greater than 0. This parameter is adjusted to the length of the smallest set of one or more segments that includes the input selection.

### `GetStrokesFromTextRange` [out, retval]

Upon return, contains a pointer to the collection of strokes that corresponds to the known range of recognized text.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | Cannot allocate stroke handler helper object. |

## Remarks

To further clarify **GetStrokesFromTextRange**, consider a collection of strokes that has been recognized and for which the best alternate for those strokes is "how are you". The parameter passed to the method is some range within (or possibly all of) this string result. This alternate contains five segments, one for each word and one for each space. The strokes returned correspond to the smallest set of segments that include all of the input range. If the *selectionStart* parameter is 0, and the *selectionLength* parameter is 5, creating a range corresponding to the "how a" of the result string, then the strokes returned are all of the recognized strokes that make up the segments "how are". This is the smallest set of segments that includes the input range.

In both word and character based recognizers, spaces are counted as a character. If the input selection corresponds to a space character, then this method returns and empty [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## See also

[GetStrokesFromStrokeRanges Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-getstrokesfromstrokeranges)

[GetTextRangeFromStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-gettextrangefromstrokes)

[IInkRecognition Alternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))