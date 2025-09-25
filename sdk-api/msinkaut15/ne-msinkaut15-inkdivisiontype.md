# InkDivisionType enumeration

## Description

Defines values for the structural types within the [IInkDivisionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult) object.

## Constants

### `IDT_Segment:0`

A recognition segment.

### `IDT_Line:1`

A line of handwriting that contains one or more recognition segments.

### `IDT_Paragraph:2`

A block of strokes that contains one or more lines of handwriting.

### `IDT_Drawing:3`

Ink that is not text.

## See also

[DivisionType Property](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionunit-get_divisiontype)

[IInkDivisionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult)

[IInkDivisionUnit Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionunit)

[ResultByType Method](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nf-msinkaut15-iinkdivisionresult-resultbytype)