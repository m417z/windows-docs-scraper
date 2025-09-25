# LINE_METRICS enumeration

## Description

Represents the lines found in a recognition segment.

## Constants

### `LM_BASELINE:0`

Requests baseline metrics. For an example that shows the baseline of a segment, see the Remarks section.

### `LM_MIDLINE:1`

Requests midline metrics. For an example that shows the midline of a segment, see the remarks section.

### `LM_ASCENDER:2`

Requests ascender metrics. For an example that shows the ascender line of a segment, see the Remarks section.

### `LM_DESCENDER:3`

Requests descender metrics. For an example that shows the descender line of a segment, see the Remarks section.

## Remarks

The following example shows the baseline, midline, ascender line, and descender line of a segment.

![Illustration showing components of line metrics](https://learn.microsoft.com/windows/win32/api/rectypes/images/af81489d-317e-499e-a78b-702519efe530.gif)
For East Asian languages written horizontally, the descender line and baseline are located at the bottom of the characters and the ascender line at the top of the characters. The midline is between the ascender and descender lines.

For East Asian languages written vertically, the descender line is the leftmost edge, the ascender line is the rightmost edge, and baseline is between the descender and ascender lines. The midline for Komoji characters is the leftmost edge and the location for punctuation characters depends on the character.