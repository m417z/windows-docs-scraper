# IAnchor::Shift

## Description

The **IAnchor::Shift** method shifts the anchor forward or backward within a text stream.

## Parameters

### `dwFlags` [in]

Bit fields that are used to avoid anchor positioning.

| Value | Meaning |
| --- | --- |
| **TS_SHIFT_COUNT_ONLY** | The anchor is not shifted. If the flag is not set (*dwFlags* = 0), the anchor will be shifted as specified by the other parameter settings. |

### `cchReq` [in]

The number of characters to move the anchor within the text stream.

### `pcch` [out]

The actual number of characters moved within the text stream. The method will set *pcch* to zero if it fails.

### `paHaltAnchor` [in]

Reference to an anchor that blocks the shift. Set to **NULL** to avoid blocking the shift.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The shift failed. |
| **E_INVALIDARG** | An input parameter value is invalid. |
| **E_NOTIMPL** | The *dwFlags* parameter value is not implemented in this method. |

## Remarks

*cchReq* and *pcch* parameters can be negative, meaning a shift backward in the text stream, or positive, meaning a shift forward. The actual number of characters shifted can be less than *cchReq* if the beginning or end of the document is encountered, a region boundary is encountered, or if *paHaltAnchor* receives an anchor that blocks the shift.

If *paHaltAnchor* receives an anchor that blocks the shift, the application will truncate the shift at the position occupied by *paHaltAnchor.* If *paHaltAnchor* is not within the span of text covered by the shift, it has no relevance to the shift and is ignored.

For example, if the anchor referenced by *paHaltAnchor* lies 8 characters ahead of the anchor in the stream, and a client calls **Shift** (0, 10, pcch, paHaltAnchor), then on exit the anchor will have moved only 8 characters. If the anchor referenced by *paHaltAnchor* is equal to the current anchor to be moved, then **Shift** will return successfully without moving the anchor at all. In this case *pcch* will be 0.

The anchor shift is always blocked by region boundaries, as if the beginning or end of the document were encountered. This will be indicated on exit by the actual shift *pcch* being smaller in absolute value than the requested shift *cchReq*. In this case, clients can use [IAnchor::ShiftRegion](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-shiftregion) to shift the anchor into an adjacent region.

## See also

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::ShiftRegion](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-shiftregion)