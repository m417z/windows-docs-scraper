# DWRITE_TEXT_METRICS1 structure

## Description

Contains the metrics associated with text after layout.All coordinates are in device independent pixels (DIPs).

**DWRITE_TEXT_METRICS1** extends [DWRITE_TEXT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_metrics)
to include the height of the formatted text.

## Members

### `heightIncludingTrailingWhitespace`

The height of the formatted text taking into account the trailing whitespace at the end of each line. This is
pertinent for vertical text.

### `DWRITE_TEXT_METRICS`