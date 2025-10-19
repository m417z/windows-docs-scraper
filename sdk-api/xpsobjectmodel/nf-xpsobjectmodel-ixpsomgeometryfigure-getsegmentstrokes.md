# IXpsOMGeometryFigure::GetSegmentStrokes

## Description

Gets stroke definitions for the figure's segments.

## Parameters

### `segmentCount` [in, out]

The size of the array that is referenced by *segmentStrokes*. This parameter must not be **NULL**.

If the method returns successfully, *segmentCount* will contain the number of elements that are returned in the array referenced by *segmentStrokes*.

If *segmentStrokes* is **NULL** when the method is called, *segmentCount* must be set to zero.

 If a **NULL** pointer is returned in *segmentStrokes*, the value of *segmentCount* will contain the required buffer size, specified as the number of elements.

### `segmentStrokes` [in, out]

An array that has the same number of elements as specified in *segmentCount*. If the caller requires that this method return only the required buffer size, set this value to **NULL**.

If the array is large enough, this method copies the segment stroke values into the array and returns, in *segmentCount*, the number of copied segment stroke values. If *segmentData* is **NULL** or references a buffer that is not large enough, a **NULL** pointer will be returned, no data will be copied, and *segmentCount* will contain the required buffer size that is specified as the number of elements.

The following table shows the possible values of an element in the array that is referenced by *segmentStrokes*.

| Value | Meaning |
| --- | --- |
| **TRUE** | The segment is stroked. |
| **FALSE** | The segment is not stroked. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *segmentCount* is **NULL**. |
| **ERROR_MORE_DATA** | *segmentStrokes* is **NULL** or references a buffer that is not large enough to receive the segment stroke data. *segmentCount* contains the required number of elements. |

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)