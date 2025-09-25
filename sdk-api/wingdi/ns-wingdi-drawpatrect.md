# DRAWPATRECT structure

## Description

The **DRAWPATRECT** structure defines a rectangle to be created.

## Members

### `ptPosition`

The upper-left corner of the rectangle, in logical units.

### `ptSize`

The lower-right corner of the rectangle, in logical units.

### `wStyle`

The style of the rectangle. It can be one of the following.

| Value | Meaning |
| --- | --- |
| 0 | Black rectangle. |
| 1 | White rectangle. |
| 2 | Gray rectangle. Used with **wPattern**. |

### `wPattern`

Amount of grayness of the rectangle, as a percentage (0-100). A value of 0 means a white rectangle and 100 means a black rectangle. This is only used when **wStyle** is 2.

## Remarks

This structure is used with the [DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85)) printer escape.

## See also

[DRAWPATTERNRECT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd162495(v=vs.85))

[Print Spooler API Structures](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-structures)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)