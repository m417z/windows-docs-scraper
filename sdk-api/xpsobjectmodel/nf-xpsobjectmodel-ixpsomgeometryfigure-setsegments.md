# IXpsOMGeometryFigure::SetSegments

## Description

Sets the segment information and data points for segments in the figure.

## Parameters

### `segmentCount` [in]

The number of segments.

This value is also the number of elements in the arrays that are referenced by *segmentTypes* and *segmentStrokes*.

### `segmentDataCount` [in]

The number of segment data points.

This value is also the number of elements in the array that is referenced by *segmentData*.

### `segmentTypes` [in]

An array of [XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type) variables. The value of *segmentCount* specifies the number of elements in this array.

### `segmentData` [in]

An array of segment data values. The value of *segmentDataCount* specifies the number of elements in this array.

### `segmentStrokes` [in]

An array of segment stroke values. The value of *segmentCount* specifies the number of elements in this array.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *segmentTypes* contains a value of unrecognized type. <br><br>Alternatively, the number of entries in the *segmentData* array is greater than the number of entries in the *segmentTypes* array. |
| **E_POINTER** | *segmentTypes*, *segmentData*, or *segmentStrokes* is **NULL**. |
| **XPS_E_INVALID_FLOAT** | *segmentData* contains a **FLOAT** value that is infinite or is not a number (NAN). |
| **XPS_E_MISSING_SEGMENT_DATA** | The array that is passed in *segmentData* has fewer entries than the array passed in *segmentTypes*. |
| **XPS_E_NEGATIVE_FLOAT** | An entry in the array that is passed in *segmentData* contains a negative value, but it must contain a non-negative value. |

## Remarks

A geometry segment is described by the start point, the segment type, and additional parameters whose values are determined by the segment type. The coordinates for the start point of the first segment are a property of the geometry figure and are set by calling [SetStartPoint](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-setstartpoint). The start point of each subsequent segment is the end point of the preceding segment.

The number of data values that define a line segment depends on the segment type. The table that follows describes the specific set of required data values that must be used for each segment type. The values in the segment data array that is passed in the *segmentData* parameter must correspond with the [XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type) values in the array that is passed in the *segmentTypes* parameter. For example, if the first line segment has a segment type value of **XPS_SEGMENT_TYPE_LINE**, the first two data values in the *segmentData* array will be the x and y coordinates of the end point of that segment; if the next segment has a segment type value of **XPS_SEGMENT_TYPE_BEZIER**, the next six values in the *segmentData* array will describe the characteristics of that segment; and so on for each line segment in the geometry figure.

| Segment type | Required data values |
| --- | --- |
| XPS_SEGMENT_TYPE_LINE<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_LINE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_line.png) | Two data values:<br><br>x-coordinate of the segment line's end point.<br><br>y-coordinate of the segment line's end point. |
| XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE<br><br>![Diagram of an XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE figure segment.](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_lc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_sc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE<br><br>![Diagram of an XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE figure segment.](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_lcc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_arc_scc.png) | Five data values:<br><br>x-coordinate of the arc's end point.<br><br>y-coordinate of the arc's end point.<br><br>Length of the ellipse's radius along the x-axis.<br><br>Length of the ellipse's radius along the y-axis.<br><br>Rotation angle. |
| XPS_SEGMENT_TYPE_BEZIER<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_BEZIER figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_bezier.png) | Six data values:<br><br>x-coordinate of the Bezier curve's first control point.<br><br>y-coordinate of the Bezier curve's first control point.<br><br>x-coordinate of the Bezier curve's second control point.<br><br>y-coordinate of the Bezier curve's second control point.<br><br>x-coordinate of the Bezier curve's end point.<br><br>y-coordinate of the Bezier curve's end point. |
| XPS_SEGMENT_TYPE_QUADRATIC_BEZIER<br><br>![A diagram that shows an example of an XPS_SEGMENT_TYPE_QUADRATIC_BEZIER figure segment](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/segment_type_quad_bezier.png) | Four data values:<br><br>x-coordinate of the Quad Bezier curve's control point.<br><br>y-coordinate of the Quad Bezier curve's control point.<br><br>x-coordinate of the Quad Bezier curve's end point.<br><br>y-coordinate of the Quad Bezier curve's end point. |

To get the segment types in the figure, call [GetSegmentTypes](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmenttypes).

The following code examples demonstrate one way to create and populate the buffers required by **SetSegments**.

In the first code example, the **AddSegmentDataToArrays** method takes the data points that describe a single segment and stores them in the three different data buffers required by the **SetSegments** method. The data buffers that are passed as arguments to **AddSegmentDataToArrays** are managed by the calling method as shown in the code example that follows **AddSegmentDataToArrays**.

```cpp
HRESULT
AddSegmentDataToArrays(
    XPS_SEGMENT_TYPE        segmentType,
    BOOL                    segmentStroke,
    FLOAT                   *segmentPoints,
    UINT32                  *segmentsAvailable,
    UINT32                  *segmentPointsAvailable,
    XPS_SEGMENT_TYPE        **segmentTypeBuffer,
    BOOL                    **segmentStrokeBuffer,
    FLOAT                   **segmentPointBuffer
)
/*
Description:

Populates the buffers required by IXpsOMGeometryFigure::SetSegmentData
using data and buffers provided by the calling method.

Parameters:

segmentType
    IN: XPS_SEGMENT_TYPE value that specifies the segment type for
        the current segment.

segmentStroke
    IN: BOOL value that specifies whether the current segment
        is stroked.

*segmentPoints
    IN: pointer to an array of FLOAT values that specify the
        segment's data points. The number of values in the array
        depend on the value of the segmentType parameter.

*segmentsAvailable
    IN: the number of values that remain unused in the
        segmentTypeBuffer and the segmentStrokeBuffer.
        This value must be >= 1 when calling the method.
    OUT:  the number of values that remain unused in the
        segmentTypeBuffer and the segmentStrokeBuffer after
        segmentType and segmentStroke have been added. If the
        method was successful, the returned value is one less
        than the value passed in to the method.

*segmentPointsAvailable
    IN: the number of values that remain unused in the
        segmentPointBuffer.    This value must be greater-than or equal
        to the number of points required by the segmentType value.
    OUT:  the number of values that remain unused in the
        segmentPointBuffer after the segmentPoints have been added.
        The returned value depends on the segmentType value.

**segmentTypeBuffer
    IN: the first free element in the buffer that receives the segment
        type values.
    OUT: the first free element in the buffer that receives the segment
        type values. If the method is successful, this will be the element
        after the element pointed to by this value before the method
        was called.

**segmentStrokeBuffer
    IN: the first free element in the buffer that receives the segment
        stroke values.
    OUT: the first free element in the buffer that receives the segment
        stroke values. If the method is successful, this will be the element
        after the element pointed to by this value before the method
        was called.

**segmentPointBuffer
    IN: the first free element in the buffer that receives the segment
        point values.
    OUT: the first free element in the buffer that receives the segment
        point values. If the method is successful, the element referenced
        by this value will depend on the segment type.

Remarks.
1) the buffers and values passed into this method are managed by
    the calling method.

2) if the value returned in segmentsAvailable is 0, segmentTypeBuffer
    and segmentStrokeBuffer point to invalid memory.

3) if the value returned in segmentPointsAvailable is 0, segmentPointBuffer
    point to invalid memory.

*/
{
    HRESULT hr = S_OK;

    // test to see if there is sufficient space in the
    // segmentTypeBuffer and the segmentStrokeBuffer before
    // proceeding
    if (*segmentsAvailable == 0)
    {
        hr = HRESULT_FROM_WIN32(ERROR_MORE_DATA);
    }

    if (SUCCEEDED(hr))
    {
        // process the data based on the segment type
        switch (segmentType)
        {
            case    XPS_SEGMENT_TYPE_ARC_LARGE_CLOCKWISE:
            case    XPS_SEGMENT_TYPE_ARC_LARGE_COUNTERCLOCKWISE:
            case    XPS_SEGMENT_TYPE_ARC_SMALL_CLOCKWISE:
            case    XPS_SEGMENT_TYPE_ARC_SMALL_COUNTERCLOCKWISE:
                if (*segmentPointsAvailable >= 5)
                {
                    // 5 data points
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<arc end point (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<arc end point (y)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<arc radius (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<arc radius (y)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<arc angle
                    *segmentPointsAvailable -= 5;
                }
                else
                {
                    hr = HRESULT_FROM_WIN32(ERROR_MORE_DATA);
                }
                break;
            case    XPS_SEGMENT_TYPE_BEZIER:
                if (*segmentPointsAvailable >= 6)
                {
                    // 6 data points
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<control point 1 (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<control point 1 (y)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<control point 2 (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<control point 2 (y)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<end point (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<end point (y)
                    *segmentPointsAvailable -= 6;
                }
                else
                {
                    hr = HRESULT_FROM_WIN32(ERROR_MORE_DATA);
                }
                break;
            case    XPS_SEGMENT_TYPE_LINE:
                if (*segmentPointsAvailable >= 2)
                {
                    // 2 data points
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<end point (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<end point (y)
                    *segmentPointsAvailable -= 2;
                }
                else
                {
                    hr = HRESULT_FROM_WIN32(ERROR_MORE_DATA);
                }
                break;
            case    XPS_SEGMENT_TYPE_QUADRATIC_BEZIER:
                if (*segmentPointsAvailable >= 4)
                {
                    // 4 data points
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<control point 2 (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<control point 2 (y)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<end point (x)
                    *(*segmentPointBuffer)++ = *segmentPoints++; //<end point (y)
                    *segmentPointsAvailable -= 4;
                }
                else
                {
                    hr = HRESULT_FROM_WIN32(ERROR_MORE_DATA);
                }
                break;
            default:
                // unrecognized segment type
                hr = E_UNEXPECTED;
                break;
        }

    }

    if (SUCCEEDED(hr))
    {
        // Copy segment type and segment stroke values
        // to array and decrement number of array values
        // that remain unused.
        //
        // The space available for these operations was
        // tested at the beginning of the method.
        *(*segmentTypeBuffer)++ = segmentType;
        *(*segmentStrokeBuffer)++ = segmentStroke;
        *segmentsAvailable--;
    }

    return hr;
}

```

In this code example, **UpdateSegmentData** creates the data buffers required by the **SetSegments** method and calls the **AddSegmentDataToArrays** method from the preceding code example to populate them with the segment data. After the buffers have been populated, **SetSegments** is called to add this data to the geometry figure.

**Note** The actual segment data is not shown in these code examples.

```cpp
HRESULT
UpdateSegmentData (
    IXpsOMGeometryFigure    *geometryFigure,
    UINT32                  segmentCount,
    UINT32                  segmentDataCount
)
/*
    Note that this method is not complete and only includes
    the code necessary to show how the SetSegments call is used.

    In this sample, the geometryFigure, segmentCount, and
    segmentDataCount values are assumed to have been initialized
    outside of this example.
*/
{
    HRESULT             hr = S_OK;
    XPS_SEGMENT_TYPE    segmentType = (XPS_SEGMENT_TYPE)0;
    BOOL                segmentStroke = FALSE;
    FLOAT               segmentPoints = 0;
    UINT32              segmentsAvailable = 0;
    UINT32              segmentPointsAvailable = 0;
    // these buffers are sized and allocated based on
    //    the segment data to store.
    XPS_SEGMENT_TYPE    *segmentTypeBuffer = NULL;
    BOOL                *segmentStrokeBuffer = NULL;
    FLOAT               *segmentPointBuffer = NULL;

    XPS_SEGMENT_TYPE    *nextSegmentTypeValue = NULL;
    BOOL                *nextSegmentStrokeValue = NULL;
    FLOAT               *nextSegmentPointValue = NULL;

    // segment data is created outside of this example

    // allocate buffers as required using information
    // from segment data. This can be dynamic or static
    // depending on how the segment information is managed.
    // This example assumes that the segment information
    // does not change during this method.

    // initialize "next" pointers to point to the first
    // element in each array.
    nextSegmentTypeValue = segmentTypeBuffer;
    nextSegmentStrokeValue = segmentStrokeBuffer;
    nextSegmentPointValue = segmentPointBuffer;

    // for each segment in the figure, add the
    // segment data to the buffers

        hr = AddSegmentDataToArrays(
                segmentType,
                segmentStroke,
                &segmentPoints,
                &segmentsAvailable,
                &segmentPointsAvailable,
                &nextSegmentTypeValue,
                &nextSegmentStrokeValue,
                &nextSegmentPointValue);

    if (SUCCEEDED(hr))
    {
        // set segment data
        hr = geometryFigure->SetSegments (
            segmentCount,
            segmentDataCount,
            segmentTypeBuffer,
            segmentPointBuffer,
            segmentStrokeBuffer);
    }
    // clean up buffers

    return hr;
}

```

## See also

[GetSegmentTypes](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgeometryfigure-getsegmenttypes)

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SEGMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_segment_type)