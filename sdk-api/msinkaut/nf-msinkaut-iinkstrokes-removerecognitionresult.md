# IInkStrokes::RemoveRecognitionResult

## Description

Removes the [RecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-get_recognitionresult) that is associated with the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

To set a recognition result on an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection, use the [SetResultOnStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-setresultonstrokes) method.

## See also

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))