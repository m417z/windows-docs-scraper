# D2D1_PATH_SEGMENT enumeration

## Description

Indicates whether a segment should be stroked and whether the join between this segment and the previous one should be smooth. This enumeration allows a bitwise combination of its member values.

## Constants

### `D2D1_PATH_SEGMENT_NONE:0x00000000`

The segment is joined as specified by the [ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle) interface, and it is stroked.

### `D2D1_PATH_SEGMENT_FORCE_UNSTROKED:0x00000001`

The segment is not stroked.

### `D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN:0x00000002`

The segment is always joined with the one preceding it using a round line join, regardless of which [D2D1_LINE_JOIN](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_line_join) enumeration is specified by the [ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle) interface. If this segment is the first segment and the figure is closed, a round line join is used to connect the closing segment with the first segment. If the figure is not closed, this setting has no effect on the first segment of the figure. If [ID2D1SimplifiedGeometrySink::SetSegmentFlags](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-setsegmentflags) is called just before [ID2D1SimplifiedGeometrySink::EndFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-endfigure), the join between the closing segment and the last explicitly specified segment is affected.

### `D2D1_PATH_SEGMENT_FORCE_DWORD:0xffffffff`

## See also

[ID2D1SimplifiedGeometrySink::SetSegmentFlags](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-setsegmentflags)

[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)