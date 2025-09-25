# IInkRecognizerContext::BackgroundRecognize

## Description

Causes the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object to recognize the associated strokes collection and fire a [Recognition](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognition) event when recognition is complete.

## Parameters

### `CustomData` [in, optional]

Specifies any application-defined data that is available to the application in the [Recognition](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognition) event. This parameter may be a VARIANT of type VT_EMPTY or VT_NULL if no data needs to be passed. The default value is **NULL**.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_NO_STROKES_TO_RECOGNIZE** | No strokes exist. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method specifies that ink recognition is performed asynchronously. To recognize ink synchronously, call the [Recognize](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-recognize) method.

This method recognizes only the best result string. Alternates are not created. To perform recognition that creates a list of available alternates, call the [BackgroundRecognizeWithAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognizewithalternates) method.

The [Recognition](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognition) event is not raised if the recognizer does not recognize anything.

## See also

[BackgroundRecognizeWithAlternates Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognizewithalternates)

[Data Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkextendedproperty-get_data)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)