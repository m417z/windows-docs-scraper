# wsprintfA function

## Description

Writes formatted data to the specified buffer. Any arguments are converted and copied to the output buffer according to the corresponding format specification in the format string. The function appends a terminating null character to the characters it writes, but the return value does not include the terminating null character in its character count.

**Note** Do not use. Consider using one of the following functions instead: [StringCbPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfa), [StringCbPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfexa), [StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa), or [StringCchPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfexa). See Security Considerations.

## Parameters

### `unnamedParam1` [out]

Type: **LPTSTR**

The buffer that is to receive the formatted output. The maximum size of the buffer is 1,024 bytes.

### `unnamedParam2` [in]

Type: **LPCTSTR**

The format-control specifications. In addition to ordinary ASCII characters, a format specification for each argument appears in this string. For more information about the format specification, see the Remarks section.

### `...`

One or more optional arguments. The number and type of argument parameters depend on the corresponding format-control specifications in the *lpFmt* parameter.

## Return value

Type: **int**

If the function succeeds, the return value is the number of characters stored in the output buffer, not counting the terminating null character.

If the function fails, the return value is less than the length of the expected output. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The format-control string contains format specifications that determine the output format for the arguments following the *lpFmt* parameter. Format specifications, discussed below, always begin with a percent sign (%). If a percent sign is followed by a character that has no meaning as a format field, the character is not formatted (for example, %% produces a single percent-sign character).

The format-control string is read from left to right. When the first format specification (if any) is encountered, it causes the value of the first argument after the format-control string to be converted and copied to the output buffer according to the format specification. The second format specification causes the second argument to be converted and copied, and so on. If there are more arguments than format specifications, the extra arguments are ignored. If there are not enough arguments for all of the format specifications, the results are undefined.

A format specification has the following form:

**%**[**-**][**#**][**0**][*width*][*.precision*]*type*

Each field is a single character or a number signifying a particular format option. The *type* characters that appear after the last optional format field determine whether the associated argument is interpreted as a character, a string, or a number. The simplest format specification contains only the percent sign and a type character (for example, %s). The optional fields control other aspects of the formatting. Following are the optional and required fields and their meanings.

| Field | Meaning |
| --- | --- |
| - | Pad the output with blanks or zeros to the right to fill the field width, justifying output to the left. If this field is omitted, the output is padded to the left, justifying it to the right. |
| # | Prefix hexadecimal values with 0x (lowercase) or 0X (uppercase). |
| 0 | Pad the output value with zeros to fill the field width. If this field is omitted, the output value is padded with blank spaces. |
| *width* | Copy the specified minimum number of characters to the output buffer. The *width* field is a nonnegative integer. The width specification never causes a value to be truncated; if the number of characters in the output value is greater than the specified width, or if the *width* field is not present, all characters of the value are printed, subject to the precision specification. |
| .*precision* | For numbers, copy the specified minimum number of digits to the output buffer. If the number of digits in the argument is less than the specified precision, the output value is padded on the left with zeros. The value is not truncated when the number of digits exceeds the specified precision. If the specified precision is 0 or omitted entirely, or if the period (.) appears without a number following it, the precision is set to 1.<br><br>For strings, copy the specified maximum number of characters to the output buffer. |
| *type* | Output the corresponding argument as a character, a string, or a number. This field can be any of the following values.<br><br>`c`<br><br>Single character. This value is interpreted as type **CHAR** by **wsprintfA** and type **WCHAR** by **wsprintfW**. Note **wsprintf** is a macro defined as **wsprintfA** (Unicode not defined) or **wsprintfW** (Unicode defined).<br><br>`C`<br><br>Single character. This value is interpreted as type **WCHAR** by **wsprintfA** and type **CHAR** by **wsprintfW**. Note **wsprintf** is a macro defined as **wsprintfA** (Unicode not defined) or **wsprintfW** (Unicode defined).<br><br>`d`<br><br>Signed decimal integer. This value is equivalent to `i`.<br><br>`hc`, `hC`<br><br>Single character. If the character has a numeric value of zero it is ignored. This value is always interpreted as type **CHAR**, even when the calling application defines Unicode.<br><br>`hd`<br><br>Signed short integer argument.<br><br>`hs`, `hS`<br><br>String. This value is always interpreted as type **LPSTR**, even when the calling application defines Unicode.<br><br>`hu`<br><br>Unsigned short integer.<br><br>`i`<br><br>Signed decimal integer. This value is equivalent to `d`.<br><br>`Ix`, `IX`<br><br>64-bit unsigned hexadecimal integer in lowercase or uppercase on 64-bit platforms, 32-bit unsigned hexadecimal integer in lowercase or uppercase on 32-bit platforms.<br><br>`lc`, `lC`<br><br>Single character. If the character has a numeric value of zero it is ignored. This value is always interpreted as type **WCHAR**, even when the calling application defines Unicode.<br><br>`ld`<br><br>Long signed integer. This value is equivalent to `li`.<br><br>`li`<br><br>Long signed integer. This value is equivalent to `ld`.<br><br>`ls`, `lS`<br><br>String. This value is always interpreted as type **LPWSTR**, even when the calling application does not define Unicode. This value is equivalent to `ws`.<br><br>`lu`<br><br>Long unsigned integer.<br><br>`lx`, `lX`<br><br>Long unsigned hexadecimal integer in lowercase or uppercase.<br><br>`p`<br><br>Pointer. The address is printed using hexadecimal.<br><br>`s`<br><br>String. This value is interpreted as type **LPSTR** by **wsprintfA** and type **LPWSTR** by **wsprintfW**. Note **wsprintf** is a macro defined as **wsprintfA** (Unicode not defined) or **wsprintfW** (Unicode defined).<br><br>`S`<br><br>String. This value is interpreted as type **LPWSTR** by **wsprintfA** and type **LPSTR** by **wsprintfW**. Note **wsprintf** is a macro defined as **wsprintfA** (Unicode not defined) or **wsprintfW** (Unicode defined).<br><br>`u`<br><br>Unsigned integer argument.<br><br>`x`, `X`<br><br>Unsigned hexadecimal integer in lowercase or uppercase. |

**Note** It is important to note that **wsprintf** uses the C calling convention (**_cdecl**), rather than the standard call (**_stdcall**) calling convention. As a result, it is the responsibility of the calling process to pop arguments off the stack, and arguments are pushed on the stack from right to left. In C-language modules, the C compiler performs this task.

To use buffers larger than 1024 bytes, use **_snwprintf**. For more information, see the documentation for the C run-time library.

> [!NOTE]
> The winuser.h header defines wsprintf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

**Reference**

[StringCbPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfa)

[StringCbPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfexa)

[StringCbVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfa)

[StringCbVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfexa)

[StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa)

[StringCchPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfexa)

[StringCchVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfa)

[StringCchVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfexa)

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[wvsprintf](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-wvsprintfa)