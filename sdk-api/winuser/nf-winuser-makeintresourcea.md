# MAKEINTRESOURCEA macro

## Description

Converts an integer value to a resource type compatible with the resource-management functions. This macro is used in place of a string containing the name of the resource.

## Parameters

### `i`

The integer value to be converted.

## Remarks

The return value should be passed only to functions which explicitly indicate that they accept **MAKEINTRESOURCE** as a parameter. For example, the resource management functions allow the return value of **MAKEINTRESOURCE** to be passed as the *lpType* or *lpName* parameters.

> [!NOTE]
> The winuser.h header defines MAKEINTRESOURCE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Resources Overview](https://learn.microsoft.com/windows/desktop/menurc/resources)