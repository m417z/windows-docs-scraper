# PathGetCharTypeA function

## Description

Determines the type of character in relation to a path.

## Parameters

### `ch` [in]

Type: **TUCHAR**

The character for which to determine the type.

## Return value

Type: **UINT**

Returns one or more of the following values that define the type of character.

| Return code | Description |
| --- | --- |
| **GCT_INVALID** | The character is not valid in a path. |
| **GCT_LFNCHAR** | The character is valid in a long file name. |
| **GCT_SEPARATOR** | The character is a path separator. |
| **GCT_SHORTCHAR** | The character is valid in a short (8.3) file name. |
| **GCT_WILD** | The character is a wildcard character. |

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathGetCharType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).