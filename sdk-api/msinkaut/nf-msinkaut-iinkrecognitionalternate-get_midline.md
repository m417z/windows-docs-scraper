# IInkRecognitionAlternate::get_Midline

## Description

Gets the midline for a [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object that represents a single line of text.

This property is read-only.

## Parameters

## Remarks

The midline corresponds to an imaginary horizontal line with which the top of the main body of each character, excluding *ascender*, is aligned. The midline also corresponds to the top of the x-height.

**Note**

If the recognition alternate spans more than one recognition segment within a line of text, then this property returns a line parallel to the baseline for the alternate. The distance of the midline above the baseline is determined by the corresponding distance within the first segment.

You can use the [AlternatesWithConstantPropertyValues](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues) method with the *propertyType* parameter set to the [Segmentation](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) recognition property globally unique identifier (GUID) to get a collection of one segment recognition alternates that correspond to a segmentation of your original alternate.

**Note** If the recognition alternate spans more than one line, this property generates an E_FAIL error. You can use the [LineAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates) property to get a collection of one line recognition alternates that corresponds to a multiple line recognition alternate.

## See also

[AlternatesWithConstantPropertyValues Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues)

[Ascender Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_ascender)

[Baseline Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_baseline)

[Descender Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_descender)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[LineAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates)