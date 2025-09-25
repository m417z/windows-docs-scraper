# IInkRecognizerContext::Recognize

## Description

Performs recognition on an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection and returns recognition results.

## Parameters

### `RecognitionStatus` [in, out]

The most recent [InkRecognitionStatus](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionstatus) value.

### `RecognitionResult` [out, retval]

When this method returns, contains a pointer to the [IInkRecognitionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult) results of a recognized collection of strokes, or else **NULL** if the recognizer could not compute a result for the ink.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_OUTOFMEMORY** | Cannot allocate memory operation. |

## Remarks

This method performs recognition synchronously. To start background or asynchronous recognition, call the [BackgroundRecognize](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize) or [BackgroundRecognizeWithAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognizewithalternates) methods.

You must use a try/catch block when calling **Recognize** because an exception is thrown when the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object contains no strokes or only deleted strokes.

## See also

[BackgroundRecognize Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize)

[BackgroundRecognizeWithAlternates Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognizewithalternates)

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))