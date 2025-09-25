# IXpsOMGeometryFigure::GetSegmentStrokePattern

## Description

Gets the [XPS_SEGMENT_STROKE_PATTERN](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_stroke_pattern) value that indicates whether the segments in the figure are stroked.

## Parameters

### `segmentStrokePattern` [out, retval]

The [XPS_SEGMENT_STROKE_PATTERN](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_stroke_pattern) value that indicates whether the segments in the figure are stroked.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *segmentStrokePattern* is **NULL**. |

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_SEGMENT_STROKE_PATTERN](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_stroke_pattern)