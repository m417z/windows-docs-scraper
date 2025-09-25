# IAnchor::ShiftRegion

## Description

Shifts the anchor into an adjacent region in the text stream.

## Parameters

### `dwFlags` [in]

Bitfields that are used to control anchor repositioning around hidden text, or to avoid actual repositioning of the anchor.

| Value | Meaning |
| --- | --- |
| **TS_SHIFT_COUNT_HIDDEN** | Specifies that the anchor will be shifted to the next region boundary, including the boundary of a hidden text region. If not set, the anchor will be shifted past any adjacent hidden text until a region of visible text is found. |
| **TS_SHIFT_COUNT_ONLY** | The anchor is not shifted. |

### `dir` [in]

Contains one of the [TsShiftDir](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tsshiftdir) values that specifies which adjacent region the anchor is moved to.

| Value | Meaning |
| --- | --- |
| **TS_SD_BACKWARD** | Specifies that the anchor will be moved to the region immediately preceding a range of text. |
| **TS_SD_FORWARD** | Specifies that the anchor will be moved to the region immediately following a range of text. |

### `pfNoRegion` [out]

Boolean value that specifies whether a shift of the anchor occurred.

| Value | Meaning |
| --- | --- |
| **TRUE** | The shift failed, and the anchor was not repositioned. |
| **FALSE** | The shift succeeded. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The shift failed. |
| **E_INVALIDARG** | An input parameter value is invalid. |

## See also

[IAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-ianchor)

[IAnchor::Shift](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-ianchor-shift)

[TS_SHIFT_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-shift--constants)

[TsShiftDir](https://learn.microsoft.com/windows/win32/api/textstor/ne-textstor-tsshiftdir)