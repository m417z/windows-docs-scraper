# IInkRecognizerContext::BackgroundRecognizeWithAlternates

## Description

Causes the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object to recognize the associated strokes collection and fire a [RecognitionWithAlternates](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognitionwithalternates) event when recognition is complete.

## Parameters

### `CustomData` [in, optional]

Optional. Specifies any application-defined data that is available to the application in the [RecognitionWithAlternates](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognitionwithalternates) event. This parameter may be a VARIANT of type VT_EMPTY or VT_NULL if no data needs to be passed. The default value is **NULL**.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| HRESULT Value | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_NO_STROKES_TO_RECOGNIZE** | No strokes exist. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method specifies that ink recognition is performed asynchronously.

To perform recognition that includes only the best result string with no alternates, call the [BackgroundRecognize](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize) method.

The [RecognitionWithAlternates](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-recognitionwithalternates) event is not raised if the recognizer does not recognize any alternates.

## See also

[BackgroundRecognize Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-backgroundrecognize)

[Data Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkextendedproperty-get_data)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)