# DashStyle enumeration

## Description

The **DashStyle** enumeration specifies the line style of a line drawn with a Windows GDI+ pen. The line can be drawn by using one of several predefined styles or a custom style.

## Constants

### `DashStyleSolid`

Specifies a solid line.

### `DashStyleDash`

Specifies a dashed line.

### `DashStyleDot`

Specifies a dotted line.

### `DashStyleDashDot`

Specifies an alternating dash-dot line.

### `DashStyleDashDotDot`

Specifies an alternating dash-dot-dot line.

### `DashStyleCustom`

Specifies a user-defined, custom dashed line.

## Remarks

A custom dashed line is created by calling the
[Pen::SetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashpattern) method, which takes an array of values for the dash lengths and the space lengths.