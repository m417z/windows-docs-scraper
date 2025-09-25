# SCRIPT_CHARPROP structure

## Description

Contains information about a single character in a run (input string). The information indicates if the character glyph is affected by surrounding letters of the run.

## Members

### `fCanGlyphAlone`

Value indicating if the shaping of a letter depends on other characters around the letter being shaped. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| TRUE | The shape of a letter is independent of surrounding characters. |
| FALSE | The shape of a letter depends on one or more adjacent characters. |

### `reserved`

Reserved.

## Remarks

One or more characters in a run, immediately preceding and/or following the letter being shaped, can influence shaping. Information about these characters can help optimize higher-level layout code, such as that used to optimize paragraph layout.

#### Examples

Let's look at an example of the use of this structure.

* A font has ligatures for letter combinations "fi" and "fl", and no others.
* The input string is "I like flying fish".
* An array of **SCRIPT_CHARPROP** structures contains one structure for each character of the input string.

For the provided input string, the array of structures has the following values in the **fCanGlyphAlone** members:

```cpp
I like flying fish
111111100111110011

```

## See also

[ScriptPlaceOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplaceopentype)

[ScriptShapeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshapeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)