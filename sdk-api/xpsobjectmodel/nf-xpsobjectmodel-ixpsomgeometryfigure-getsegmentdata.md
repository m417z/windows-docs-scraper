# IXpsOMGeometryFigure::GetSegmentData

## Description

Gets the segment data points for the geometry figure.

## Parameters

### `dataCount` [in, out]

The size of the array referenced by the *segmentData* parameter.

If the method returns successfully, *dataCount* will contain the number of elements returned in the array that is referenced by *segmentData*.

If *segmentData* is set to **NULL** when the method is called, *dataCount* must be set to zero.

 If a **NULL** pointer is returned in *segmentData*, *dataCount* will contain the required buffer size as the number of elements.

### `segmentData` [in, out]

The address of an array that has the same number of elements as specified in *dataCount*. This value can be set to **NULL** if the caller requires that the method return only the required buffer size in *dataCount*.

If the array is large enough, this method copies the segment data points into the array and returns, in *dataCount*, the number of data points that are copied. If *segmentData* is set to **NULL** or references a buffer that is not large enough, a **NULL** pointer will be returned, no data will be copied, and *dataCount* will contain the required buffer size specified as the number of elements.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *dataCount* is **NULL**. |
| **ERROR_MORE_DATA** | *segmentData* is **NULL** or references a buffer that is not large enough to receive the segment data. *dataCount* contains the required number of elements. |

## Remarks

To determine the required size of the segment data array before calling this method, call [GetSegmentDataCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentdatacount).

A geometry segment is described by the start point, the segment type, and additional parameters whose values are determined by the segment type. The coordinates for the start point of the first segment are a property of the geometry figure and are set by calling [SetStartPoint](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-setstartpoint). The start point of each subsequent segment is the end point of the preceding segment.

The values in the array returned in the *segmentData* parameter will correspond with the [XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type) values in the array returned by the [GetSegmentTypes](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmenttypes) method in the *segmentTypes* parameter. To read the segment data values correctly, you will need to know the type of each segment in the geometry figure. For example, if the first line segment has a segment type value of **XPS_SEGMENT_TYPE_LINE**, the first two data values in the *segmentData* array will be the x and y coordinates of the end point of that segment; if the next segment has a segment type value of **XPS_SEGMENT_TYPE_BEZIER**, the next six values in the *segmentData* array will describe the characteristics of that segment; and so on for each line segment in the geometry figure.

The table that follows describes the specific set of data values that are returned for each segment type. For an example of how to access this data in a program, see the code example that follows.

| Segment type | Required data values |
| --- | --- |
| XPS_SEGMENT_TYPE_LINE<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_LINE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_line.png) | Two data values:<br><br>x-coordinate of the segment line's end point.<br><br>y-coordinate of the segment line's end point. |
| XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE<br><br>![Diagram of an XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE figure segment.](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_lc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_sc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE<br><br>![Diagram of an XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE figure segment.](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_lcc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_scc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_BEZIER<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_BEZIER figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_bezier.png) | Six data values:<br><br>x-coordinate of the Bezier curve's first control point.<br><br>y-coordinate of the Bezier curve's first control point.<br><br>x-coordinate of the Bezier curve's second control point.<br><br>y-coordinate of the Bezier curve's second control point.<br><br>x-coordinate of the Bezier curve's end point.<br><br>y-coordinate of the Bezier curve's end point. |
| XPS_SEGMENT_TYPE_QUADRATIC_BEZIER<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_QUADRATIC_BEZIER figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_quad_bezier.png) | Four data values:<br><br>x-coordinate of the Quad Bezier curve's control point.<br><br>y-coordinate of the Quad Bezier curve's control point.<br><br>x-coordinate of the Quad Bezier curve's end point.<br><br>y-coordinate of the Quad Bezier curve's end point. |

The following code example accesses the different data points of each segment type in a geometry figure.

```cpp
    // currentFigure is the pointer to an IXpsOMGeometryFigure
    // that contains the segment data to examine

    HRESULT             hr = S_OK;
    UINT32              numSegments = 0;
    UINT32              numSegmentDataPoints = 0;
    XPS_SEGMENT_TYPE    *segmentTypes = NULL;
    FLOAT               *segmentDataPoints = NULL;
    BOOL                *segmentStrokes = NULL;

    // get number of segments in this figure
    hr = currentFigure->GetSegmentCount (&numSegments);

    if (SUCCEEDED(hr))
    {
        // allocate array for segment data types
        segmentTypes = new (std::nothrow) XPS_SEGMENT_TYPE[numSegments];
        if (segmentTypes == NULL) { hr = E_OUTOFMEMORY; }
    }

    if (SUCCEEDED(hr))
    {
        // allocate array for segment strokes
        segmentStrokes = new (std::nothrow) BOOL[numSegments];
        if (segmentStrokes == NULL) { hr = E_OUTOFMEMORY; }
    }

    if (SUCCEEDED(hr))
    {
        // get array of segment data types
        hr = currentFigure->GetSegmentTypes (&numSegments, segmentTypes);
    }

    if (SUCCEEDED(hr))
    {
        // get size of segment data array
        hr = currentFigure->GetSegmentDataCount (&numSegmentDataPoints);
    }

    if (SUCCEEDED(hr))
    {
        // get array to hold segment data points
        segmentDataPoints = new (std::nothrow) FLOAT[numSegmentDataPoints];
        if (segmentDataPoints == NULL) { hr = E_OUTOFMEMORY; }
    }

    if (SUCCEEDED(hr))
    {
        // get segment data points
        hr = currentFigure->GetSegmentData (
            &numSegmentDataPoints, segmentDataPoints);
    }

    if (SUCCEEDED(hr))
    {
        // process segment data
        UINT32           thisSegment = 0;
        XPS_SEGMENT_TYPE *thisSegmentType = segmentTypes;
        XPS_SEGMENT_TYPE *lastSegmentType = NULL;
        FLOAT            *thisSegmentDataPoint = segmentDataPoints;
        FLOAT            *lastSegmentsDataPoint = NULL;

        // points to element just after valid array
        // valid pointers are < this value and  >= &segmentTypes[0]
        lastSegmentType = &segmentTypes[numSegments];
        // points to element just after valid array
        // valid pointers are < this value and >= &segmentDataPoints[0]
        lastSegmentsDataPoint = &segmentDataPoints[numSegmentDataPoints];

        // look at each segment that was returned
        while (thisSegment < numSegments)
        {
            if ((thisSegmentType >= lastSegmentType) ||
                (thisSegmentDataPoint >= lastSegmentsDataPoint))
            {
                // the array data is not correct.
                hr = E_UNEXPECTED;
                break; // out of loop
            }
            else
            {
                // process the data based on the segment type
                switch (*thisSegmentType)
                {
                    case    XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE:
                    case    XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE:
                    case    XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE:
                    case    XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE:
                        {
                        // 5 data points
                        FLOAT    arcEndPoint_x = *thisSegmentDataPoint++;
                        FLOAT    arcEndPoint_y = *thisSegmentDataPoint++;
                        FLOAT    radius_x = *thisSegmentDataPoint++;
                        FLOAT    radius_y = *thisSegmentDataPoint++;
                        FLOAT    angle = *thisSegmentDataPoint++;
                        // do something with these points
                        }
                        break;
                    case    XPS_SEGMENT_TYPE_BEZIER:
                        {
                        // 6 data points
                        FLOAT    controlPoint1_x = *thisSegmentDataPoint++;
                        FLOAT    controlPoint1_y = *thisSegmentDataPoint++;
                        FLOAT    controlPoint2_x = *thisSegmentDataPoint++;
                        FLOAT    controlPoint2_y = *thisSegmentDataPoint++;
                        FLOAT    endPoint_x = *thisSegmentDataPoint++;
                        FLOAT    endPoint_y = *thisSegmentDataPoint++;
                        // do something with these points
                        }
                        break;
                    case    XPS_SEGMENT_TYPE_LINE:
                        {
                        // 2 data points
                        FLOAT    endPoint_x = *thisSegmentDataPoint++;
                        FLOAT    endPoint_y = *thisSegmentDataPoint++;
                        // do something with these points
                        }
                        break;
                    case    XPS_SEGMENT_TYPE_QUADRATIC_BEZIER:
                        {
                        // 4 data points
                        FLOAT    controlPoint_x = *thisSegmentDataPoint++;
                        FLOAT    controlPoint_y = *thisSegmentDataPoint++;
                        FLOAT    endPoint_x = *thisSegmentDataPoint++;
                        FLOAT    endPoint_y = *thisSegmentDataPoint++;
                        // do something with these points
                        }
                        break;
                    default:
                        // unrecognized segment type
                        break;
                }
                //
                thisSegment++;
                thisSegmentType++;
            }
        }
    }

    delete[] segmentTypes; segmentTypes = NULL;
    delete[] segmentStrokes; segmentStrokes = NULL;
    delete[] segmentDataPoints; segmentDataPoints = NULL;

```

## See also

[GetSegmentCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentcount)

[GetSegmentDataCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmentdatacount)

[GetSegmentTypes](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmenttypes)

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))