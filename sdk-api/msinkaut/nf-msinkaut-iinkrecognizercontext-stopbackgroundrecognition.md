# IInkRecognizerContext::StopBackgroundRecognition

## Description

Ends background recognition that was started with a call to [BackgroundRecognize](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize) or [BackgroundRecognizeWithAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognizewithalternates).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success.<br><br>This method also returns S_OK if the recognizer does not support this method. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside method. |

## Remarks

No event is fired if **StopBackgroundRecognition** is called.

Call **StopBackgroundRecognition** if you call [BackgroundRecognize](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize) or [BackgroundRecognizeWithAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognizewithalternates) one or more times. Calling **StopBackgroundRecognition** does not necessarily ensure that you get no results from a recognition process that is currently under way. It only ensures that all previous calls to **BackgroundRecognize** or **BackgroundRecognizeWithAlternates** that have not yet been processed are actually not executed.

Call this method only if you process the ink asynchronously.

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)