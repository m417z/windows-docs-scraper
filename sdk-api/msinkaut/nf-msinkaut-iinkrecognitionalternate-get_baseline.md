# IInkRecognitionAlternate::get_Baseline

## Description

Gets the baseline for a [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object that represents a single line of text.

This property is read-only.

## Parameters

## Remarks

The baseline is the imaginary horizontal line with which the base of each character, excluding decenders, is aligned. It also corresponds to the bottom of the x-height.

**Note**

If the recognition alternate spans more than one recognition segment within a line of text, then this property returns a line that begins at the first point of the baseline of the first segment in the alternate and ends at the last point of the baseline of the last segment in the alternate.

You can use the [AlternatesWithConstantPropertyValues](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues) method with the *propertyType* parameter set to the [Segmentation](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) recognition property globally unique identifier (GUID) to get a collection of one segment recognition alternates that correspond to a segmentation of your original alternate.

**Note** If the recognition alternate spans more than one line, this property generates an E_FAIL error. You can use the [LineAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates) property to get a collection of one line recognition alternates that corresponds to a multiple line recognition alternate.

## See also

[AlternatesWithConstantPropertyValues Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues)

[Ascender Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_ascender)

[Descender Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_descender)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[LineAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates)

[Midline Property [IInkRecognitionAlternate Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_midline)