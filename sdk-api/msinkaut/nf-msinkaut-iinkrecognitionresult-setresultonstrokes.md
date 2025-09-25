# IInkRecognitionResult::SetResultOnStrokes

## Description

Assigns the recognition results to the strokes that were used to create the results.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred while processing. |

## Remarks

System performance suffers if recognition results are automatically assigned to every [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection. Therefore results are not attached to an InkStrokes collection by default. To assign results to an InkStrokes collection, you must call **SetResultOnStrokes**. To return the recognition results for a InkStrokes collection, use the [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) property of the InkStrokes collection. After you assign results to a InkStrokes collection, you can then store the strokes in a [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection. These custom strokes, as well as the **IInkRecognitionResult**, can be persisted and retrieved for later use.

To return the recognition results of a collection of strokes, use the [RecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-get_recognitionresult) property.

After you assign results to a collection of strokes, you can then store the strokes in an [IInkCustomStrokes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcustomstrokes) collection. These custom strokes, as well as the [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult), can be persisted and retrieved for later use.

## See also

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[RecognitionResult Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-get_recognitionresult)