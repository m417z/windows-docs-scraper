# IInkRecognitionResult::get_TopConfidence

## Description

Gets the top alternate of the recognition result.

This property is read-only.

## Parameters

## Remarks

Of the Microsoft **recognizers**, only the Microsoft English (US) Handwriting Recognizer and the Microsoft Gesture Recognizer support confidence levels. Third party recognizers may or may not support confidence levels.

**Note** The **TopConfidence** property may change if a call to the [ModifyTopAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-modifytopalternate) method causes a change to the [TopAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topalternate) property.

## See also

[IInkRecognitionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionresult)

[InkRecognitionConfidence Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionconfidence)

[ModifyTopAlternate Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-modifytopalternate)

[TopAlternate Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionresult-get_topalternate)