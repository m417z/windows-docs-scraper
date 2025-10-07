# StrokeType enumeration

Indicates whether a stroke should be analyzed as part of a drawing or as part of writing.

## Constants

**StrokeType\_Unclassified**

The stroke might be either part of a drawing or part of writing.

**StrokeType\_Writing**

The stroke is part of writing.

**StrokeType\_Drawing**

The stroke is part of a drawing.

## Examples

The following example shows part of a stroke event handler, implemented in a similar fashion to the [C++ Event Sinks Sample](https://learn.microsoft.com/windows/win32/tablet/c---event-sinks-sample). The added stroke is checked to see if the top of its bounding box has been drawn below a margin, `drawingMargin`. If so, the [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) object, `m_spInkAnalyzer`, is set to analyze the stroke as a drawing stroke, rather than as a handwriting stroke. `CheckHResult` is a function that takes an `HRESULT` and a string, and throws an exception created with the string if the `HRESULT` is not **SUCCESS**.

```C++
IInkRectangle* bounds;
CheckHResult(pStroke->GetBoundingBox(IBBM_Default, &bounds), "IInkStrokeDisp::GetBoundingBox failed");
long top;
CheckHResult(bounds->get_Top(&top), "IInkRectangle::get_Top failed");
if (top > drawingMargin)
{
    long strokeId;
    CheckHResult(pStroke->get_ID(&strokeId), "IInkStrokeDisp::get_ID failed");
    m_pInkAnalyzer->SetStrokeType(strokeId, StrokeType_Drawing);
}
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IInkAnalyzer::SetStrokeType Method**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer-setstroketype)

