# SCRIPT_TABDEF structure

## Description

Contains definitions of the tab positions for [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse).

## Members

### `cTabStops`

Number of entries in the array indicated by **pTabStops**.

| Value | Meaning |
| --- | --- |
| 0 | Tab stops occur every eight average character widths. |
| 1 | All tab stops are the length of the first entry in the array indicated by **pTabStops**. |
| greater than 1 | The first **cTabStops** tab stops are as specified in the array indicated by **pTabStops**, and subsequent tab stops are every eight average characters. |

### `iScale`

Scale factor for **iTabOrigin** and **pTabStops** values. Values are converted to device coordinates by multiplying by the value indicated by **iScale**, then dividing by 4. If values are already in device units, set **iScale** to 4. If values are in dialog units, set **iScale** to the average character width of the dialog font. If values are multiples of the average character width for the selected font, set **iScale** to 0.

### `pTabStops`

Pointer to an array having the number of entries indicated by **cTabStops**. Each entry specifies a tab stop position. Positive values represent near-edge alignment, while negative values represent far-edge alignment. The units for the array elements are as indicated by the value of **iScale**.

### `iTabOrigin`

Initial offset, in logical units, for tab stops. Tabs start **iTabOrigin** logical units before the beginning of the string. This rule helps with situations in which multiple tabbed outputs occur on the same line.

## Remarks

This structure is ignored unless the *dwFlags* parameter is set to SSA_TAB in the [ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse) function.

## See also

[ScriptStringAnalyse](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringanalyse)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)