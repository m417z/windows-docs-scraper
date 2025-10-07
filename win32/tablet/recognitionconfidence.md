# RecognitionConfidence enumeration

Indicates the level of confidence that the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) has in the accuracy of the recognition result.

## Constants

**RecognitionConfidence\_Strong**

Strong confidence in the result or alternate.

**RecognitionConfidence\_Intermediate**

Intermediate confidence in the result or alternate.

**RecognitionConfidence\_Poor**

Poor confidence in the result or alternate.

**RecognitionConfidence\_Unknown**

The [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer) that generated the recognized text does not support confidence levels.

## Remarks

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) uses one or more [**IInkAnalysisRecognizer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalysisrecognizer) objects to convert handwriting to text.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IAnalysisAlternate::GetRecognitionConfidence Method**](https://learn.microsoft.com/windows/win32/tablet/ianalysisalternate-getrecognitionconfidence)

[**IContextNode::GetPropertyData**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-getpropertydata)

[Context Node Properties](https://learn.microsoft.com/windows/win32/tablet/context-node-properties)

[Ink Analysis Reference](https://learn.microsoft.com/windows/win32/tablet/ink-analysis-reference)

