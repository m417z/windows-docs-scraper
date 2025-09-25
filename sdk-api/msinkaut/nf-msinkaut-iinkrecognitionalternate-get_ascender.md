# IInkRecognitionAlternate::get_Ascender

## Description

Gets the ascender line for a [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object that represents a single line of text.

This property is read-only.

## Parameters

## Remarks

For western languages, the ascender corresponds to the portion of a lowercase letter that extends above the main body (the midline or x-height) of that letter such as the vertical line of a "b" that extends above the highest point of the circle in that letter. The ascender line is the imaginary horizontal line across the top of the ascenders.

**Note** If the recognition alternate spans more than one recognition segment within a line of text, then this property will return a line parallel to the baseline for the alternate. The distance of the ascender line above the baseline is determined by the corresponding distance within the first segment.You can use the [AlternatesWithConstantPropertyValues](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues) method with the *propertyType* parameter set to the [Segmentation](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) recognition property globally unique identifier (GUID) to get a collection of one segment recognition alternates that correspond to a segmentation of your original alternate.

**Note** If the recognition alternate spans more than one line, this property generates an E_FAIL error. You can use the [LineAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates) property to get a collection of one line recognition alternates that corresponds to a multiple line recognition alternate.

## See also

[AlternatesWithConstantPropertyValues Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues)

[Baseline Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_baseline)

[Descender Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_descender)

[IInkRecognitionAlternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[LineAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates)

[Midline Property [IInkRecognitionAlternate Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_midline)