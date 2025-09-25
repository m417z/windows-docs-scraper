## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class is part of the WMI Provider Framework which is now considered in final state, and no further development, enhancements, or updates will be available for non-security related issues affecting these libraries.
The [MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new development.]

The **FormatMessageW** method formats a message string.

## Parameters

### `nFormatID`

The string resource identifier that contains the unformatted message text.

### `...`

Argument list.

## Return value

CHeap_Exception

## Remarks

The **FormatMessageW** method requires a message definition as input.
The message definition is determined by *lpszFormat* or from the string resource identified by *nFormatID*.
The method copies the formatted message text to the **CHString** string, processing any embedded insert sequences if requested.

Each insert must have a corresponding parameter that follows the *lpszFormat* or *nFormatID* parameter.
Within the message text, several escape sequences are supported for dynamically formatting the message.
For a description of these escape sequences and their meanings, see the Windows **FormatMessage** function topic.

**Note** To reduce exposure to security attacks, always use a format string for **FormatMessageW**.
For example, **FormatMessageW(input)** is exploitable, and **FormatMessageW("%s", input)** is not.
Never use a user-supplied string for the format string.
If your format string is stored for a purpose such as localization, ensure that the string is protected from unauthorized write access.
If your function writes to a string rather than standard output, you may need to avoid using a trailing "%s" in the format string.

## Examples

The following code example shows you how to use **CHString::FormatMessageW**.

```cpp
CHString str;
int nAsked = 5;
int nAgree = 4;

str.FormatMessageW(L"%1!d! of %2!d! developers agree: Golf is %3%!",
   nAgree, nAsked, L"Best");
assert(str == L"4 of 5 developers agree: Golf is Best!");
```

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Format](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-format(uint_---))