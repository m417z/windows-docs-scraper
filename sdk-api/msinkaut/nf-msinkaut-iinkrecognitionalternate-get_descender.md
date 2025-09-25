# IInkRecognitionAlternate::get_Descender

## Description

Gets the descender line for an [IInkRecognitionAlternate](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate) object that represents a single line of text.

This property is read-only.

## Parameters

## Remarks

For western languages, the descender corresponds to the portion of a lowercase letter that falls below the baseline, such as the vertical line of a "p" that extends below the lowest point of the circle in that letter. The descender line is the imaginary horizontal line across the bottom of the descenders.

**Note**

If the recognition alternate spans more than one recognition segment within a line of text, then this property returns a line parallel to the baseline for the alternate. The distance of the descender line below the baseline is determined by the corresponding distance within the first segment.

You can use the [AlternatesWithConstantPropertyValues](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues) method with the *propertyType* parameter set to the [Segmentation](https://learn.microsoft.com/windows/desktop/tablet/recognitionproperty-constants) recognition property globally unique identifier (GUID) to get a collection of one segment recognition alternates that correspond to a segmentation of your original alternate.

**Note** If the recognition alternate spans more than one line, this property generates an E_FAIL error. You can use the [LineAlternates](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates) property to get a collection of one line recognition alternates that corresponds to a multiple line recognition alternate.

## See also

[AlternatesWithConstantPropertyValues Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-alternateswithconstantpropertyvalues)

[Ascender Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_ascender)

[Baseline Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_baseline)

[IInkRecognition Alternate Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognitionalternate)

[LineAlternates Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_linealternates)

[Midline Property [IInkRecognitionAlternate Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_midline)