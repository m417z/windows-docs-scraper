# CANDIDATELIST structure

## Description

Contains information about a candidate list.

## Members

### `dwSize`

Size, in bytes, of the structure, the offset array, and all candidate strings.

### `dwStyle`

Candidate style values. This member can have one or more of the following values.

| Value | Meaning |
| --- | --- |
| IME_CAND_UNKNOWN | Candidates are in a style other than listed here. |
| IME_CAND_READ | Candidates are in same reading. |
| IME_CAND_CODE | Candidates are in a code range. |
| IME_CAND_MEANING | Candidates are in same meaning. |
| IME_CAND_RADICAL | Candidates use same radical character. |
| IME_CAND_STROKES | Candidates are in same number of strokes. |

For the IME_CAND_CODE style, the candidate list has a special structure depending on the value of the **dwCount** member. If **dwCount** is 1, the **dwOffset** member contains a single DBCS character rather than an offset, and no candidate string is provided. If the **dwCount** member is greater than 1, the **dwOffset** member contains valid offsets, and the candidate strings are text representations of individual DBCS character values in hexadecimal notation.

### `dwCount`

Number of candidate strings.

### `dwSelection`

Index of the selected candidate string.

### `dwPageStart`

Index of the first candidate string in the candidate window. This varies as the user presses the PAGE UP and PAGE DOWN keys.

### `dwPageSize`

Number of candidate strings to be shown in one page in the candidate window. The user can move to the next page by pressing IME-defined keys, such as the PAGE UP or PAGE DOWN key. If this number is 0, an application can define a proper value by itself.

### `dwOffset`

Offset to the start of the first candidate string, relative to the start of this structure. The offsets for subsequent strings immediately follow this member, forming an array of 32-bit offsets.

## Remarks

The candidate strings immediately follow the last offset in the **dwOffset** array.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Structures](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-structures)