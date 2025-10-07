# InkAnalysisRecognizerGuide structure

Specifies the guide, or area where ink is drawn and recognized.

## Members

**rectWritingBox**

The invisible writing area of the recognition guide in which writing can actually take place.

**rectDrawnBox**

The rectangle that is drawn on the tablet screen and in which writing takes place.

**cRows**

The number of rows in the recognition guide box.

**cColumns**

The number of columns in the recognition guide box.

**midline**

The midline height of the recognition guide box. The midline height is the distance from the baseline to the midline, of the drawn box.

## Remarks

An **InkAnalysisRecognizerGuide** defines an expected area of input, such as a line or boxes, for characters. An **InkAnalysisRecognizerGuide** structure can be set only on an analysis hint context node (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype)). The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) uses the location of the analysis hint node and the locations of the ink strokes to associate a stroke with the analysis hint node. Any strokes with an association to the analysis hint node will have the specified **InkAnalysisRecognizerGuide** used when recognized by an **IInkAnalyzer**, provided the **IInkAnalyzer** supports the **InkAnalysisRecognizerGuide**. The values expressed in the **InkAnalysisRecognizerGuide** class are always relative to the location of the analysis hint node and are specified in ink space coordinates.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[Analysis Hint Properties](https://learn.microsoft.com/windows/win32/tablet/analysis-hint-properties)

[**IInkAnalyzer::CreateAnalysisHint Method**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer-createanalysishint)

[**IContextNode::AddPropertyData**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-addpropertydata)

[**IContextNode::GetPropertyData**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-getpropertydata)

[Ink Analysis Reference](https://learn.microsoft.com/windows/win32/tablet/ink-analysis-reference)

