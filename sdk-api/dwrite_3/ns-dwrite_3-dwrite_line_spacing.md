## Description

Sets the vertical spacing between lines of text.

## Members

### `method`

Type: **[DWRITE_LINE_SPACING_METHOD](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_line_spacing_method)**

Method used to determine line spacing.

### `height`

Type: **FLOAT**

Spacing between lines. The interpretation of this parameter depends upon the line spacing method, as follows:

* Line spacing: ignored
* uniform line spacing: explicit distance in DIPs between lines
* proportional line spacing: a scaling factor to be applied to the computed line height;
  for each line, the height of the line is computed as for default line spacing, and the scaling factor is applied to that value.

### `baseline`

Type: **FLOAT**

Distance from top of line to baseline.
The interpretation of this parameter depends upon the line spacing method, as follows:

* default line spacing: ignored
* uniform line spacing: explicit distance in DIPs from the top of the line to the baseline
* proportional line spacing: a scaling factor applied to the computed baseline; for each line,
  the baseline distance is computed as for default line spacing, and the scaling factor is applied to that value.

### `leadingBefore`

Type: **FLOAT**

Proportion of the entire leading distributed before the line. The allowed value is between 0 and 1.0. The remaining
leading is distributed after the line. It is ignored for the default and uniform line spacing methods.
The leading that is available to distribute before or after the line depends on the values of the height and
baseline parameters.

### `fontLineGapUsage`

Type: **[DWRITE_FONT_LINE_GAP_USAGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ne-dwrite_3-dwrite_font_line_gap_usage)**

Specify whether [DWRITE_FONT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_font_metrics)::lineGap value should be part of the line metrics.