# IInkRecognitionAlternate::get_LineAlternates

## Description

Gets the [IInkRecognitionAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates) collection in which each alternate in the collection is on a separate line.

This property is read-only.

## Parameters

## Remarks

If you have a recognition alternate for a paragraph of ink, you can use the **LineAlternates** property to get a collection of recognition alternates in which each alternate represents a separate line of the paragraph.

This property is an alternative to calling the [AlternatesWithConstantPropertyValues](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues) method with the *propertyType* parameter set to the [LineNumber](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) value of the RecognitionProperty constants. For more information about properties of alternates see the RecognitionProperty constants.

**Note** The [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object automatically determines the line metrics when drawing ink.

## See also

[AlternatesWithConstantPropertyValues Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues)

[ConfidenceAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_confidencealternates)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[IInkRecognitionAlternates Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternates)

[RecognitionProperty Constants](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants)