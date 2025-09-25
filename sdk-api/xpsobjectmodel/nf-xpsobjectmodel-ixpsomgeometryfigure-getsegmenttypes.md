# IXpsOMGeometryFigure::GetSegmentTypes

## Description

Gets the types of segments in the figure.

## Parameters

### `segmentCount` [in, out]

The size of the array that is referenced by *segmentTypes* (see below). This parameter must not be **NULL**.

If the method returns successfully, *segmentCount* will contain the number of elements that are returned in the array referenced by *segmentTypes*.

If *segmentTypes* is **NULL** when the method is called, *segmentCount* must be set to zero.

 If a **NULL** pointer is returned in *segmentTypes*, the value of *segmentCount* will contain the required buffer size, specified as the number of elements.

### `segmentTypes` [in, out]

An array of [XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type) values that has the same number of elements as specified in *segmentCount*. If the caller requires that only the specified buffer size be returned, set this value to **NULL**.

If the array is large enough, this method will copy the [XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type) values into the array and return, in *segmentCount*, the number of the copied values. If *segmentTypes* is **NULL** or references a buffer that is not large enough, a **NULL** pointer will be returned, no data will be copied, and *segmentCount* will contain the required buffer size, which is specified as the number of elements.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *segmentCount* is **NULL**. |
| **ERROR_MORE_DATA** | *segmentTypes* is **NULL** or references a buffer that is not large enough to receive the [XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type) data. *segmentCount* contains the required number of elements. |

## Remarks

For an example of how to use this method in a program, see the code example in [GetSegmentData](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentdata).

## See also

[GetSegmentCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentcount)

[GetSegmentData](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentdata)

[GetSegmentDataCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentdatacount)

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type)