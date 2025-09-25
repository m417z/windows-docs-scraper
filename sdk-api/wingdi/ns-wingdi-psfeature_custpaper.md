# PSFEATURE_CUSTPAPER structure

## Description

The **PSFEATURE_CUSTPAPER** structure contains information about a custom paper size for a PostScript driver. This structure is used with the [GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85)) printer escape function.

## Members

### `lOrientation`

Indicates the custom paper orientation. This member can be 0 to 3 if custom page size is selected. Otherwise, it is 1 and all other structure members are zero

### `lWidth`

Custom page width, in points.

### `lHeight`

Custom page height, in points.

### `lWidthOffset`

Custom page width offset, in points.

### `lHeightOffset`

Custom page height offset, in points.

## Remarks

For the semantics of the **lOrientation**, **lWidth**, **lHeight**, **lWidthOffset**, and **lHeightOffset** members, please refer to "Custom Page Size Parameters" in "PostScript Printer Description File Format Specification" v.4.3.

## See also

[GET_PS_FEATURESETTING](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd144954(v=vs.85))

[Print Spooler API Structures](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-structures)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)