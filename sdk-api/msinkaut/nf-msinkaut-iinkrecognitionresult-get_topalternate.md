# IInkRecognitionResult::get_TopAlternate

## Description

Gets the top alternate of the recognition result.

This property is read-only.

## Parameters

## Remarks

When the recognizer returns a recognition result, the recognition alternates are ranked from the highest confidence level to the lowest confidence level. The recognition alternate with the highest confidence level is selected as the top alternate.

You can use the [ModifyTopAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-modifytopalternate) method to change which recognition alternate is the top alternate.

## See also

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[ModifyTopAlternate Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-modifytopalternate)