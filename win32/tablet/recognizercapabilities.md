# RecognizerCapabilities enumeration

Specifies the attributes of an [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer).

## Constants

**RC\_None**

No capabilities specified.

**RC\_DoNotCare**

Ignores all other flags that are set.

**RC\_Object**

Supports object recognition; otherwise, recognizes only text.

**RC\_FreeInput**

Supports free input, where ink is entered without the use of a recognition guide, such as a line or a box.

**RC\_LinedInput**

Supports lined input, which is similar to writing on lined paper.

**RC\_BoxedInput**

Supports boxed input, where each character or word is entered in a box.

**RC\_CharacterAutoCompletionInput**

Supports character Autocomplete. Recognizers that support character Autocomplete require boxed input.

**RC\_RightAndDown**

Supports handwriting input in right and down order, such as in western languages and some East Asian languages.

**RC\_LeftAndDown**

Supports handwriting input in left and down order, such as in Hebrew and Arabic languages.

**RC\_DownAndLeft**

Supports handwriting input in down and left order, such as in some East Asian languages.

**RC\_DownAndRight**

Supports handwriting input in down and right order, such as in some East Asian languages.

**RC\_ArbitraryAngle**

Supports text written at arbitrary angles.

**RC\_Lattice**

Supports returning a lattice as an alternative a string for handwriting recognition results.

**RC\_AdviseInkChange**

Supports interrupting background recognition, such as when the ink has changed.

**RC\_StrokeReorder**

Supports that stroke order, spatial and temporal, is handled as part of the recognition operation. The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) does not reorder strokes before sending ink to the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer).

**RC\_Personalizable**

Supports personalized handwriting, where the recognizer improves recognition when exposed to the same handwriting over time.

**RC\_PrefersArbitraryAngle**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) need not rotate the handwriting to a horizontal orientation before sending the ink to the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer).

**RC\_PrefersParagraphBreaking**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) should send entire paragraphs of ink to the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer), allowing the **IInkAnalysisRecognizer** to do the line breaking and word (or character) breaking.

**RC\_PrefersSegmentationRecognition**

Recognizes only one word or character per recognition operation. The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) performs segmentation on the handwriting and sends only one segment at a time to the [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer).

## Remarks

This enumeration allows a bitwise combination of its member values. Use this enumeration to find an installed ink recognizer that supports the attributes you need.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IInkAnalysisRecognizer::GetCapabilities**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer-getcapabilities)

[Ink Analysis Reference](https://learn.microsoft.com/windows/win32/tablet/ink-analysis-reference)

