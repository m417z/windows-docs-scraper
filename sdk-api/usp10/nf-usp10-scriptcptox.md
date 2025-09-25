# ScriptCPtoX function

## Description

Generates the x offset from the left end or leading edge of a run to either the leading or trailing edge of a logical character [cluster](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary).

## Parameters

### `iCP` [in]

Logical character position in the run. This parameter corresponds to the offset of any logical character in the cluster.

### `fTrailing` [in]

**TRUE** to use the trailing edge of the logical character cluster to compute the offset. This parameter is set to **FALSE** to use the leading edge of the logical character cluster.

### `cChars` [in]

Number of characters in the run.

### `cGlyphs` [in]

Number of glyphs in the run.

### `pwLogClust` [in]

Pointer to the logical clusters.

### `psva` [in]

Pointer to a [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr) array of visual attributes.

### `piAdvance` [in]

Pointer to an advance widths value.

### `psa` [in]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure. The **fLogicalOrder** member specifies the end of the run from which to measure the offset. If the flag is set, the leading edge of the run is used. If the flag is not set, the left end of the run is used.

### `piX` [out]

Pointer to the buffer in which the function retrieves the x position of the caret.

## Return value

Returns 0 if successful. This function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

The leading or trailing edge of the character and the leading edge of a run depend on the direction of text in the run.

For scripts in which the caret is conventionally placed in the middle of clusters (for example, Arabic and Hebrew), the retrieved x position of the carat can be an interpolated position for any code point in the line.

For scripts in which the caret is conventionally snapped to the boundaries of clusters (for example, Thai and Indian), the x position is snapped to the requested edge of the cluster containing the logical character position indicated by *iCP*.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[ScriptXtoCP](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptxtocp)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)