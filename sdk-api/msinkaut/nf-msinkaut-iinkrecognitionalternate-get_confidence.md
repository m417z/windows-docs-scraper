# IInkRecognitionAlternate::get_Confidence

## Description

Gets the level of confidence (strong, intermediate, or poor) that a recognizer has in the recognition of an [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object or a gesture.

This property is read-only.

## Parameters

## Remarks

For a list of confidence values that may be returned, see the [InkRecognitionConfidence](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionconfidence) enumeration type.

**Note** Confidence evaluation is available for all gesture recognizers in the current release of Windows XP Tablet PC Edition.

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object:

If the alternate represents a phrase or sentence, the value represents the lowest confidence level of a recognition segment found in the phrase or sentence. However, if the alternate represents a word, the value represents the confidence level of the word.

**Note** This property throws an exception if the [IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) that generates the [IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) does not support confidence levels.

Of the Microsoft recognizers, only the Microsoft English (US) Handwriting Recognizer and the Microsoft Gesture Recognizer support confidence levels. Third party recognizers may or may not support confidence levels.

## See also

[IInkGesture Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture)

[IInkRecognition Alternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[InkRecognitionConfidence Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognitionconfidence)