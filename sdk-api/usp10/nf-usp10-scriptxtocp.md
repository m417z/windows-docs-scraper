# ScriptXtoCP function

## Description

Generates the leading or trailing edge of a logical character cluster from the x offset of a run.

## Parameters

### `iX` [in]

Offset, in logical units, from the end of the run specified by the **fLogicalOrder** member of the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure indicated by the *psa* parameter.

### `cChars` [in]

Count of logical code points in the run.

### `cGlyphs` [in]

Count of glyphs in the run.

### `pwLogClust` [in]

Pointer to an array of logical clusters.

### `psva` [in]

Pointer to an array of [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr) structures containing the visual attributes for the glyph.

### `piAdvance` [in]

Pointer to an array of advance widths.

### `psa` [in]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure. The **fLogicalOrder** member indicates **TRUE** to use the leading edge of the run, or **FALSE** to use the trailing edge.

### `piCP` [out]

Pointer to a buffer in which this function retrieves the character position corresponding to the x coordinate.

### `piTrailing` [out]

Pointer to a buffer in which this function retrieves the distance, in code points, from the leading edge of the logical character to the *iX* position. If this value is 0, the *iX* position is at the leading edge of the logical character. For more information, see the Remarks section.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

The values passed to this function normally are the results of earlier calls to other Uniscribe functions. See [Managing Caret Placement and Hit Testing](https://learn.microsoft.com/windows/desktop/Intl/managing-caret-placement-and-hit-testing) for details.

The leading and trailing edges of the logical character are determined by the direction of text in the run (left-to-right or right-to-left). For the left-to-right direction, the leading edge is the same as the left edge. For the right-to-left direction, the leading edge is the right edge.

For scripts in which the caret is conventionally placed in the middle of a cluster, for example, Arabic and Hebrew, the retrieved character position can be for any code point in the line. In this case, the *piTrailing* parameter is set to either 0 or 1.

For scripts in which the caret is conventionally snapped to the boundaries of a cluster, the retrieved character position is always the position of the first code point in a cluster (considered logically). The *piTrailing* parameter is set to 0 or to the number of code points in the cluster.

The appropriate caret position for a mouse hit is always the retrieved character position plus the distance indicated by *piTrailing*.

When *iX* indicates a position outside the run, **ScriptXtoCP** acts as if there is an extra infinitely large character beyond each end of the run. This results in the behavior shown in the following table.

| *iX* position (outside the run) | Result |
| --- | --- |
| Before the run, that is: *iX* < 0 if run is left-to-right, or *iX* >= sum of advances if run is right-to-left | Value of *piCP* is -1 and value of *piTrailing* is 0 |
| After the run, that is: *iX* >= sum of advances if run is left-to-right, or *iX* < 0 if run is right-to-left | Value of *piCP* is value of *cChars* and value of *piTrailing* is 1 |

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)